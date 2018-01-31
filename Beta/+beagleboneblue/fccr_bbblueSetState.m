classdef fccr_bbblueSetState < matlab.System ...
        & matlab.system.mixin.internal.CustomIcon ...
        & matlab.system.mixin.Propagates ...
        & coder.ExternalDependency

    % Beaglebone Blue rc_set_state

    %#codegen
    %#ok<*EMCA>

    properties(Nontunable)
        state = 'UNINITIALIZED'; % oversample rate x1 with 182 Hz update rate
    end

    properties(Constant, Hidden)
        stateSet = matlab.system.StringSet({'UNINITIALIZED','RUNNING','PAUSED','EXITING'})
        blockPlatform = 'BB BLUE'
    end

    properties(Hidden)
        stateEnum
    end

    methods
        % Constructor
        function obj = fccr_bbblueSetState(varargin)
            %This would allow the code generation to proceed with the
            %p-files in the installed location of the support package.
            coder.allowpcode('plain');
            % Support name-value pair arguments when constructing the object.
            setProperties(obj,nargin,varargin{:});
        end

        function stateVal = get.stateEnum(obj)
            switch(obj.state)
                case 'UNINITIALIZED'
                    stateVal = uint8(0); % update rate 182 HZ
                case 'RUNNING'
                    stateVal = uint8(1); % update rate 133 HZ
                case 'PAUSED'
                    stateVal = uint8(2); % update rate 87 HZ
                case 'EXITING'
                    stateVal = uint8(3); % update rate 51 HZ
            end
        end

    end

    methods(Access = protected)
        function setupImpl(obj)
            % Perform one-time calculations, such as computing constants
            if coder.target('Rtw')
                coder.cinclude('fccr_bbblue_driver.h');
                coder.updateBuildInfo('addDefines','_roboticscape_in_use_');
            end
        end

        function [~] = stepImpl(obj)
            % Implement algorithm. Calculate y as a function of input u and
            %  discrete states.
            if coder.target('Rtw')
                coder.ceval('fccr_set_state',obj.stateEnum);
            end
        end

        function releaseImpl(~)
            % Release resources, such as file handles
            if coder.target('Rtw')
                coder.ceval('rc_set_state',uint8(3));
            end
        end

        function num = getNumInputsImpl(~)
            % Define total number of inputs for system
            num = 0;
        end

        function num = getNumOutputsImpl(~)
            % Define total number of outputs for system with optional
            % outputs
            num = 3;
        end

        function varargout = getOutputNamesImpl(~)
            % Return output port names for System block
            varargout{1} = 'Temp';
            varargout{2} = 'Pres';
            varargout{3} = 'Alt';
        end

        function varargout = getOutputSizeImpl(~)
            % Return size for each output port
            varargout{1} = [1 1];
            varargout{2} = [1 1];
            varargout{3} = [1 1];
        end

        function varargout = getOutputDataTypeImpl(~)
            % Return data type for each output port
            varargout{1} = 'double';
            varargout{2} = 'double';
            varargout{3} = 'double';
        end

        function varargout = isOutputComplexImpl(~)
            % Return true for each output port with complex data
            varargout{1} = false;
            varargout{2} = false;
            varargout{3} = false;
        end

        function varargout = isOutputFixedSizeImpl(~)
            % Return true for each output port with fixed size
            varargout{1} = true;
            varargout{2} = true;
            varargout{3} = true;
        end

        function st = getSampleTimeImpl(obj)
            st = obj.SampleTime;
        end

        function maskDisplayCmds = getMaskDisplayImpl(obj)
            Oversample = ['Oversample : ' obj.oversample];
            Filter = ['Filter Coefficient : ' obj.filter];
            blockName = 'Barometer';
            maskDisplayCmds = [ ...
                ['color(''white'');',newline]...
                ['plot([100,100,100,100]*1,[100,100,100,100]*1);',newline]...
                ['plot([100,100,100,100]*0,[100,100,100,100]*0);',newline]...
                ['color(''blue'');',newline] ...
                ['text(100, 92, '' ' obj.blockPlatform ' '', ''horizontalAlignment'', ''right'');',newline]  ...
                ['color(''black'');',newline]...
                ['text(52,32,' [''' ' Oversample ''',''horizontalAlignment'',''center'');' newline]]   ...
                ['color(''black'');',newline]...
                ['text(52,12,' [''' ' Filter ''',''horizontalAlignment'',''center'');' newline]]   ...
                ['color(''black'');',newline]...
                ['text(52,52,' [''' ' blockName ''',''horizontalAlignment'',''center'');' newline]]   ...
                ['color(''black'');',newline]...
                ];
        end
    end

    methods (Static)
        function name = getDescriptiveName()
            name = 'BeagleBone Blue Barometer';
        end

        function b = isSupportedContext(context)
            b = context.isCodeGenTarget('rtw');
        end

        function updateBuildInfo(buildInfo, context)
            if context.isCodeGenTarget('rtw')
                spkgRootDir = codertarget.bbblue.internal.getSpPkgRootDir;
                % Include Paths
                addIncludePaths(buildInfo, fullfile(spkgRootDir, 'include'));
                addIncludeFiles(buildInfo, 'MW_bbblue_driver.h');
                addIncludeFiles(buildInfo, 'fccr_bbblue_driver.h');

                % Update buildInfo
                rootDir = fullfile(fileparts(mfilename('fullpath')),'.');
                buildInfo.addIncludePaths(rootDir);

                % Source Files
                systemTargetFile = get_param(buildInfo.ModelName,'SystemTargetFile');
                if isequal(systemTargetFile,'ert.tlc')
                    % Add the following when not in rapid-accel simulation
                    buildInfo.addLinkFlags('-lroboticscape');
                    %addSourcePaths(buildInfo, fullfile(spkgRootDir, 'src'));
                end
            end
        end
    end %methods

    methods(Access = protected, Static)
        function simMode = getSimulateUsingImpl(~)
            simMode = 'Interpreted execution';
        end

        function header = getHeaderImpl
            % Define header panel for System block dialog
            header = matlab.system.display.Header(mfilename('class'), ...
                'Title', 'Barometer', ...
                'Text',['Output Temperature, Pressure, and Altitude from the Barometer.' newline newline ...
                'Use the oversample drop down to set the oversample rate.' newline ...
                'Use the filter dropdown to set the internal first order filter coefficient or select off to apply your own filtering.'], ...
                'ShowSourceLink', false);
        end

        function groups = getPropertyGroupsImpl
            % Oversample
            State = matlab.system.display.internal.Property('state', 'Description', 'State');

            PropertyListOut = {State};
            % Create mask display
            Group = matlab.system.display.Section(...
                'PropertyList',PropertyListOut);

            groups = Group;
        end

        function flag = showSimulateUsingImpl
            % Return false if simulation mode hidden in System block dialog
            flag = false;
        end
    end
end
