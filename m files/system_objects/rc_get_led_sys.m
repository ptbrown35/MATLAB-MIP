classdef rc_get_led_sys < matlab.System ...
        & coder.ExternalDependency ...
        & matlab.system.mixin.Propagates ...
        & matlab.system.mixin.CustomIcon

    % Robotics Cape get_led function
    % Runs rc_set_led in stepImpl

    % Copyright 2016 The MathWorks, Inc.

    properties % block parameters
        led = 1 % 0 (green), 1 (red)
    end

    methods
        % Constructor : this must be here
        function obj = rc_get_led_sys(varargin)
            coder.allowpcode('plain');
            % Support name-value pair arguments when constructing the object.
            setProperties(obj,nargin,varargin{:});
        end
    end

    methods (Access = protected)

        function y = stepImpl(obj) % Implement step (a.k.a. output at every step)
            
            y = int8(0);
            if coder.target('Rtw') %  Generated Code: call external output code
                y = coder.ceval('rc_get_led', obj.led);
                disp(['Rtw - rc_set_led(rc_led_t led)']);

            elseif coder.target('MATLAB') % Simulation: display values
                disp(['MATLAB - Step: Output = ' num2str(y)]);  % You could display y
                %only in matlab when called using Matlab only
            end
        end
    end

    methods (Access = protected)
        %% Define input properties
        function num = getNumInputsImpl(~)
            num = 0;
        end

        function num = getNumOutputsImpl(~)
            num = 1;
        end
        
        function varargout = getOutputNamesImpl(~)
            varargout{1} = 'y';
        end
        
        function flag = isOutputSizeLockedImpl(~,~)
            flag = true;
        end
        
        function varargout = isOutputFixedSizeImpl(~,~)
            varargout{1} = true;
        end
        
        function flag = isOutputComplexityLockedImpl(~,~)
            flag = true;
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
            icon = 'rc_get_led_sys';
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
            name = 'rc_get_led';
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
