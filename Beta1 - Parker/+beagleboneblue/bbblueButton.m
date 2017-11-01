classdef bbblueButton < matlab.System ...
        &  matlab.system.mixin.internal.CustomIcon & matlab.system.mixin.Propagates...
        &  matlabshared.svd.BlockSampleTime & coder.ExternalDependency
    
    
    %#codegen
    %#ok<*EMCA>
    properties(Nontunable)
        %Button
        Button = 'Mode'      
    end
    
    properties(Constant, Hidden)
        ButtonSet = matlab.system.StringSet({'Mode','Pause'})
        blockPlatform = 'BB BLUE'
    end
    
    
    methods
        % Constructor
        function obj = bbblueButton(varargin)
            %This would allow the code generation to proceed with the
            %p-files in the installed location of the support package.
            coder.allowpcode('plain');            
            % Support name-value pair arguments when constructing the object.
            setProperties(obj,nargin,varargin{:});
        end
        
        
    end
    
    methods(Access = protected)
        function setupImpl(~)
            % Perform one-time calculations, such as computing constants
            if coder.target('Rtw')
                coder.cinclude('MW_bbblue_driver.h');      
                coder.updateBuildInfo('addDefines','_roboticscape_in_use_');
            end
        end
        
        
        
        function data = stepImpl(obj)
            % Implement algorithm. Calculate y as a function of input u and
            %  discrete states.
            data = uint8(0);
            if coder.target('Rtw')
                if isequal(obj.Button,'Mode')
                    data=coder.ceval('rc_get_mode_button');
                else
                    data=coder.ceval('rc_get_pause_button');
                end
            end
        end
        
        
        function num = getNumInputsImpl(~)
            % Define total number of inputs for system with optional inputs
            num = 0;
            % if obj.UseOptionalInput
            %     num = 2;
            % end
        end
        
        function num = getNumOutputsImpl(~)
            % Define total number of outputs for system with optional
            % outputs
            num = 1;
        end
        
        function varargout = getOutputNamesImpl(~)
            % Return output port names for System block
            varargout{1} ='state';
        end
        %
        function varargout = getOutputSizeImpl(~)
            % Return size for each output port
            varargout{1} =[1 1];
        end
        %
        function varargout = getOutputDataTypeImpl(~)
            % Return data type for each output port
            varargout{1} ='uint8';
        end
        %
        function varargout = isOutputComplexImpl(~)
            % Return true for each output port with complex data
            varargout{1} =false;
        end
        %
        function varargout = isOutputFixedSizeImpl(~)
            % Return true for each output port with fixed size
            varargout{1} =true;
        end
        
        function st = getSampleTimeImpl(obj)
            st = obj.SampleTime;
        end
        
        function maskDisplayCmds = getMaskDisplayImpl(obj)
            blockName = 'Button';
            maskDisplayCmds = [ ...
                ['color(''white'');',newline]...
                ['plot([100,100,100,100]*1,[100,100,100,100]*1);',newline]...
                ['plot([100,100,100,100]*0,[100,100,100,100]*0);',newline]...
                ['color(''blue'');',newline] ...
                ['text(100, 92, '' ' obj.blockPlatform ' '', ''horizontalAlignment'', ''right'');',newline]  ...
                ['color(''black'');',newline]...
                ['text(52,12,' [''' ' obj.Button ''',''horizontalAlignment'',''center'');' newline]]   ...
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
                
                % Update buildInfo
                rootDir = fullfile(fileparts(mfilename('fullpath')),'.');
                buildInfo.addIncludePaths(rootDir);
                
                systemTargetFile = get_param(buildInfo.ModelName,'SystemTargetFile');
                if isequal(systemTargetFile,'ert.tlc')
                    % Add the following when not in rapid-accel simulation
                    buildInfo.addLinkFlags('-lroboticscape');
                end
                
            end
        end
    end %methods
    
    methods(Access = protected, Static)
        function header = getHeaderImpl
            % Define header panel for System block dialog
               header = matlab.system.display.Header(mfilename('class'), ...
                'Title', 'Button', ...
                'Text',['Read the state of the Button on BeagleBone Blue hardware.' newline newline ...
                'The block outputs the state of the Button as a uint8 data.' newline newline 'The output is 1 when the button is pressed and 0 when released.'], ...
                'ShowSourceLink', false);
        end
        
        function groups = getPropertyGroupsImpl            
            % Button
            Button = matlab.system.display.internal.Property('Button', 'Description', 'Button');
            % Sample Time
            Sampletime = matlab.system.display.internal.Property('SampleTime', 'Description', 'Sample time');
            
          
            PropertyListOut = {Button, Sampletime};
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
