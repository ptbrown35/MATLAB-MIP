classdef rc_initialize_barometer_sys < matlab.System ...
        & coder.ExternalDependency ...
        & matlab.system.mixin.CustomIcon

    % Robotics Cape barometer initialize function
    % Only executes rc_initialize_barometer on Simulink setupImpl

    % Copyright 2016 The MathWorks, Inc.

    properties % block parameters

    end

    methods
        % Constructor : this must be here
        function obj = rc_initialize_sys(varargin)
            coder.allowpcode('plain');
            % Support name-value pair arguments when constructing the object.
            setProperties(obj,nargin,varargin{:});
        end
    end

    methods (Access = protected)

        function setupImpl(obj) % Implement setup (runs at beginning of model one time)

            if coder.target('Rtw') % Generated Code: call external init code
                coder.cinclude('roboticscape.h');
                coder.ceval('rc_initialize_barometer');
                disp(['RC Cape Barometer initialized']);
            elseif coder.target('MATLAB') % Simulation: display valuesg
               disp(['MATLAB - Sim Initialized']);
                %Don't do anything in Matlab interpretive mode
            end

        end

    end

    methods (Access = protected)
        %% Define input properties
        function num = getNumInputsImpl(~)
            num = 0;
        end

        function num = getNumOutputsImpl(~)
            num = 0;
        end

        function icon = getIconImpl(~)
            % Define a string as the icon for the System block in Simulink.
            icon = 'rc_initialize_barometer_sys';
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
            name = 'rc_barometer_initialize';
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
