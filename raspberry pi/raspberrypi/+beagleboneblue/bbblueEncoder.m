classdef bbblueEncoder < matlab.System ...
        &  matlab.system.mixin.internal.CustomIcon & matlab.system.mixin.Propagates...
        & matlabshared.svd.BlockSampleTime & coder.ExternalDependency
    % Untitled2 Add summary here
    %
    % This template includes the minimum set of functions required
    % to define a System object with discrete state.
    
    %#codegen
    %#ok<*EMCA>
    properties(Nontunable)
        %Channel
        Channel = '1'
        %Reset mode
        Mode = 'No reset'
    end
    
    properties(Constant, Hidden)
        ChannelSet = matlab.system.StringSet({'1','2','3','4'});
        ModeSet = matlab.system.StringSet({'No reset','Reset at each Sample time','Reset by external signal'});
        blockPlatform = 'BB BLUE'
    end
    
    properties(Hidden)
        ChannelEnum
        ModeEnum
    end
    
    methods
        % Constructor
        function obj = bbblueEncoder(varargin)
            %This would allow the code generation to proceed with the
            %p-files in the installed location of the support package.
            coder.allowpcode('plain');          
            % Support name-value pair arguments when constructing the object.
            setProperties(obj,nargin,varargin{:});
        end
        
        function val = get.ChannelEnum(obj)
            switch(obj.Channel)
                case '1'
                    val = uint8(1);
                case '2'
                    val = uint8(2);
                case '3'
                    val = uint8(3);
                case '4'
                    val = uint8(4);
            end
        end
        
        function val = get.ModeEnum(obj)
            switch(obj.Mode)
                case 'No reset'
                    val = uint8(1);
                case 'Reset at each Sample time'
                    val = uint8(2);
                case 'Reset by external signal'
                    val = uint8(3);
            end
        end
    end
    
    methods(Access = protected)
        function setupImpl(obj)
            % Perform one-time calculations, such as computing constants
            if coder.target('Rtw')
                coder.cinclude('MW_bbblue_driver.h');
                coder.updateBuildInfo('addDefines','_roboticscape_in_use_');
            end
        end
        
        
        
        function data = stepImpl(obj,varargin)
            % Implement algorithm. Calculate y as a function of input u and
            %  discrete states.
            data = int32(0);
            if coder.target('Rtw')
                if isequal(obj.Mode, 'Reset by external signal')
                    data=coder.ceval('getEncoderValue',obj.ChannelEnum,obj.ModeEnum,varargin{1});
                else
                    data=coder.ceval('getEncoderValue',obj.ChannelEnum,obj.ModeEnum,int8(0));
                end
            end
        end
        
        
        function num = getNumInputsImpl(obj)
            % Define total number of inputs for system with optional inputs
            if isequal(obj.Mode,'Reset by external signal')
                num = 1;
            else
                num = 0;
            end
        end
        
        function num = getNumOutputsImpl(~)
            % Define total number of outputs for system with optional
            % outputs
            num = 1;
        end
        
        function varargout = getOutputNamesImpl(obj)
            % Return output port names for System block
            varargout{1} ='state';
        end
        %
        function varargout = getOutputSizeImpl(obj)
            % Return size for each output port
            varargout{1} =[1 1];
        end
        %
        function varargout = getOutputDataTypeImpl(obj)
            % Return data type for each output port
            varargout{1} ='int32';
        end
        %
        function varargout = isOutputComplexImpl(obj)
            % Return true for each output port with complex data
            varargout{1} =false;
        end
        %
        function varargout = isOutputFixedSizeImpl(obj)
            % Return true for each output port with fixed size
            varargout{1} =true;
        end
        
        function st = getSampleTimeImpl(obj)
            st = obj.SampleTime;
        end
        
        function maskDisplayCmds = getMaskDisplayImpl(obj)
            channel = ['Channel : ' obj.Channel];
            blockName = 'Encoder';
            maskDisplayCmds = [ ...
                ['color(''white'');',newline]...
                ['plot([100,100,100,100]*1,[100,100,100,100]*1);',newline]...
                ['plot([100,100,100,100]*0,[100,100,100,100]*0);',newline]...
                ['color(''blue'');',newline] ...
                ['text(100, 92, '' ' obj.blockPlatform ' '', ''horizontalAlignment'', ''right'');',newline]  ...
                ['color(''black'');',newline]...
                ['text(52,12,' [''' ' channel ''',''horizontalAlignment'',''center'');' newline]]   ...
                ['color(''black'');',newline]...
                ['text(52,52,' [''' ' blockName ''',''horizontalAlignment'',''center'');' newline]]   ...
                ['color(''black'');',newline]...
                ];
            
        end
        
        
        
    end %methods
    
    methods (Static)
        function name = getDescriptiveName()
            name = 'BeagleBone Blue Button';
        end
        
        function b = isSupportedContext(context)
            b = context.isCodeGenTarget('rtw');
        end
        
        function updateBuildInfo(buildInfo, context)
            if context.isCodeGenTarget('rtw')
                spkgRootDir = codertarget.raspi.internal.getSpPkgRootDir;
                % Include Paths
                addIncludePaths(buildInfo, fullfile(spkgRootDir, 'include'));
                addIncludeFiles(buildInfo, 'MW_bbblue_driver.h');
                
                % Update buildInfo
                rootDir = fullfile(fileparts(mfilename('fullpath')),'.');
                buildInfo.addIncludePaths(rootDir);
                
                
                % Source Files
                systemTargetFile = get_param(buildInfo.ModelName,'SystemTargetFile');
                if isequal(systemTargetFile,'ert.tlc')
                    % Add the following when not in rapid-accel simulation
                    buildInfo.addLinkFlags('-lroboticscape');
                    addSourcePaths(buildInfo, fullfile(spkgRootDir, 'src'));
                    addSourceFiles(buildInfo, 'MW_bbblue_encoder.c', fullfile(spkgRootDir, 'src'), 'BlockModules');
                end
                
            end
        end
    end %methods
    
    methods(Access = protected, Static)
        function header = getHeaderImpl
            % Define header panel for System block dialog
            
            header = matlab.system.display.Header(mfilename('class'), ...
                'Title','Encoder', ...
                'Text',['Measure the rotation of a motor.' newline newline ...
                'The block emits tick count as int32 value.' newline newline ...
                'Use the Reset option drop-down to either reset the encoder output at each sample time' ...
                ' or when a non-zero input is provided at the input port.'], ...
                'ShowSourceLink', false);
        end
        
        function flag = showSimulateUsingImpl
            % Return false if simulation mode hidden in System block dialog
            flag = false;
        end
    end
end
