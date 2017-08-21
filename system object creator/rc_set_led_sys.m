% Filename: rc_set_led_sys.m
% Last Modified: August 20, 2017
% Author: Parker Brown <ptbrown@ucsd.edu>
% Description: Set LED function block

classdef rc_set_led_sys < matlab.System ...
        & coder.ExternalDependency ...
        & matlab.system.mixin.CustomIcon ...
        & matlab.system.mixin.Propagates

    properties % Public, tunable properties
        led = 1
    end
    
    methods
        % Constructor : this must be here
        function obj = rc_set_led_sys(varargin)
            coder.allowpcode('plain');
            % Support name-value pair arguments when constructing the object.
            setProperties(obj,nargin,varargin{:});
        end
    end
    
    methods (Access = protected)
        
        function y = stepImpl(obj,u) % Implement step
            
            y = int8(0);
            if coder.target('Rtw') %  Generated Code: call external output code
                y = coder.ceval('rc_set_led', obj.led, u);
                disp('Rtw - rc_set_led');
            elseif coder.target('MATLAB') % Simulation
                disp(['MATLAB - Step: Input = ' num2str(u)]);
            end
        end
    end
    
    methods (Access = protected)
        %% Define input properties
        function num = getNumInputsImpl(~)
            num = 1;
        end
        
        function num = getNumOutputsImpl(~)
            num = 1;
        end
        
        function varargout = getInputNamesImpl(~)
            varargout{1} = 'u';
        end
        
        function varargout = getOutputNamesImpl(~)
            varargout{1} = 'y';
        end
        
        function flag = isInputSizeLockedImpl(~,~)
            flag = true;
        end
        
        function flag = isOutputSizeLockedImpl(~,~)
            flag = true;
        end
        
        function varargout = isInputFixedSizeImpl(~,~)
            varargout{1} = true;
        end
        
        function varargout = isOutputFixedSizeImpl(~,~)
            varargout{1} = true;
        end
        
        function flag = isInputComplexityLockedImpl(~,~)
            flag = true;
        end
        
        function flag = isOutputComplexityLockedImpl(~,~)
            flag = true;
        end
        
        function varargout = isInputComplexImpl(~)
            varargout{1} = false;
        end
        
        function varargout = isOutputComplexImpl(~)
            varargout{1} = false;
        end
        
        function sz_1 = getOutputSizeImpl(~)
            sz_1 = [1 1];
        end
        
        function out = getOutputDataTypeImpl(~)
            out = 'int8';
        end
        
        function validateInputsImpl(~, u)
            if isempty(coder.target)
                % Run this always in Simulation
                validateattributes(u,{'uint8','uint16','uint32','uint64', ...
                    'int8','int16','int32','int64','single','double'}, ...
                    {'scalar','>=',0,'<=',255'},'','input');
            end
        end
        
        function validateOutputsImpl(~, y)
            if isempty(coder.target)
                % Run this always in Simulation
                validateattributes(y,{'uint8','uint16','uint32','uint64', ...
                    'int8','int16','int32','int64','single','double'}, ...
                    {'scalar','>=',-128,'<=',127'},'','output');
            end
        end
        
        function icon = getIconImpl(~)
            % Define a string as the icon for the System block in Simulink.
            icon = 'rc_set_led_sys';
        end
    end
    
    methods (Static, Access = protected)
        function simMode = getSimulateUsingImpl(~)
            simMode = 'Interpreted execution';
        end
        
        function isVisible = showSimulateUsingImpl
            isVisible = false;
        end
    end
    
    methods (Static)
        
        function name = getDescriptiveName()
            name = 'rc_set_led';
        end
        
        function b = isSupportedContext(context)
            b = context.isCodeGenTarget('rtw');
        end
        
        function updateBuildInfo(buildInfo, context)
            if context.isCodeGenTarget('rtw')
                % Update buildInfo
                rootDir = fullfile(fileparts(mfilename('fullpath')),'.');
                buildInfo.addIncludePaths(rootDir);
                buildInfo.addLinkFlags('-lroboticscape');
            end
        end
    end
end

