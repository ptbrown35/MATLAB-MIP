classdef bbblueLED < matlab.System ...
        & coder.ExternalDependency ...
        & matlab.system.mixin.Propagates ...
        &  matlab.system.mixin.internal.CustomIcon
    
    
    % LED block for BeagleBone Blue Hardware
    
    % Copyright 2017 The MathWorks, Inc.
    
    %#codegen
    %#ok<*EMCA>
    properties(Nontunable)
        LED = 'Red'
        
    end
    
    properties(Constant, Hidden)
        LEDSet = matlab.system.StringSet({'Red','Green'})
        blockPlatform = 'BB BLUE'
    end
    
    properties(Hidden)
        LEDEnum
    end
    
    
    methods
        % Constructor : this must be here
        function obj = bbblueLED(varargin)
            coder.allowpcode('plain');
            % Support name-value pair arguments when constructing the object.
            setProperties(obj,nargin,varargin{:});
        end
        
        function led = get.LEDEnum(obj)
            if isequal(obj.LED, 'Green')
                led = uint8(0);
            else
                led = uint8(1);
            end
        end
    end
    
    methods (Access=protected)
        
        function setupImpl(obj) % Implement setup  %These function names stay the same
            if coder.target('Rtw') % Generated Code: call external init code
                coder.cinclude('MW_bbblue_driver.h');
                coder.updateBuildInfo('addDefines','_roboticscape_in_use_');
            end
        end
        
        function stepImpl(obj,u) % Implement step (a.k.a. output)   %These function names stay the same
            if coder.target('Rtw') %  Generated Code: call external output code
                coder.ceval('rc_set_led', obj.LEDEnum,uint8(u));
            end
        end
    end
    
    methods (Access=protected)
        %% Define input properties
        function num = getNumInputsImpl(~)
            num = 1;
        end
        
        function num = getNumOutputsImpl(~)
            num = 0;
        end
        
        function flag = isInputSizeLockedImpl(~,~)
            flag = true;
        end
        
        function varargout = isInputFixedSizeImpl(~,~)
            varargout{1} = true;
        end
        
        function flag = isInputComplexityLockedImpl(~,~)
            flag = true;
        end
        
        function varargout = isInputComplexImpl(~)
            varargout{1} = false;
        end
        
        function validateInputsImpl(~, u)
            if isempty(coder.target)
                % Run this always in Simulation
                validateattributes(u,{'uint8','uint16','uint32','uint64', ...
                    'int8','int16','int32','int64','single','double'}, ...
                    {'scalar','>=',0,'<=',255'},'','input');
            end
        end
        
        function maskDisplayCmds = getMaskDisplayImpl(obj)
            blockName = 'LED';
            maskDisplayCmds = [ ...
                ['color(''white'');',newline]...
                ['plot([100,100,100,100]*1,[100,100,100,100]*1);',newline]...
                ['plot([100,100,100,100]*0,[100,100,100,100]*0);',newline]...
                ['color(''blue'');',newline] ...
                ['text(100, 92, '' ' obj.blockPlatform ' '', ''horizontalAlignment'', ''right'');',newline]  ...
                ['color(''black'');',newline]...
                ['text(52,12,' [''' ' obj.LED ''',''horizontalAlignment'',''center'');' newline]]   ...
                ['color(''black'');',newline]...
                ['text(52,52,' [''' ' blockName ''',''horizontalAlignment'',''center'');' newline]]   ...
                ['color(''black'');',newline]...
                ];
            
        end
    end
    
    methods (Static, Access=protected)
        function simMode = getSimulateUsingImpl(~)
            simMode = 'Interpreted execution';
        end
        
        function isVisible = showSimulateUsingImpl
            isVisible = false;
        end
        
        function header = getHeaderImpl
            % Define header panel for System block dialog
                   
             header = matlab.system.display.Header(mfilename('class'), ...
                'Title', 'LED', ...
                'Text',['Set the state of the LED onboard BeagleBone Blue Hardware' newline newline ...
                'The block accepts uint8 data.' newline newline 'The LED turns ''ON'' for a non-zero input data.'], ...
                'ShowSourceLink', false);
        end
    end
    
    methods (Static)
        function name = getDescriptiveName()
            name = 'LED Block';
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
    end
end
