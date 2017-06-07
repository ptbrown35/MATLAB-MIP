classdef rc_set_led < matlab.System ...
        & coder.ExternalDependency ...
        & matlab.system.mixin.CustomIcon

    % Blinks the LED passed as a parameter
    % light is on when input is nonzero
    % No rc_initialize, no rc_cleanup
    % Runs rc_set_led in stepImpl

    % Copyright 2016 The MathWorks, Inc.

    properties (Nontunable) % block parameters
        rc_led_t = 1
    end

    methods
        % Constructor : this must be here
        function obj = rc_set_led(varargin)
            coder.allowpcode('plain');
            % Support name-value pair arguments when constructing the object.
            setProperties(obj,nargin,varargin{:});
        end
    end

    methods (Access = protected)

        function stepImpl(obj,u) % Implement step (a.k.a. output at every step)

            if coder.target('Rtw') %  Generated Code: call external output code
                coder.ceval('rc_set_led', obj.rc_led_t, u);
                disp('Rtw - rc_set_led(rc_led_t led, int state)');

            elseif coder.target('MATLAB') % Simulation: display values
                disp(['MATLAB - Step: Input = ' num2str(u)]);  % You could display u
                %only in matlab when called using Matlab only
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

        function icon = getIconImpl(~)
            % Define a string as the icon for the System block in Simulink.
            icon = 'rc_set_led';
        end
    end

    methods (Static, Access=protected)
        function simMode = getSimulateUsingImpl(~)
            simMode = 'Interpreted execution';
        end

        function isVisible = showSimulateUsingImpl
            isVisible = false;
        end
    end

    methods (Static)
        function name = getDescriptiveName()
            name = 'Analog Output and Serial Transmit';
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
