classdef rc_cleanup_sys < matlab.System ...
        & coder.ExternalDependency ...
        & matlab.system.mixin.CustomIcon

    % Robotics Cape cleanup function
    % light is on when input is nonzero

    % Copyright 2016 The MathWorks, Inc.

    properties % block parameters
        
    end

    methods
        % Constructor : this must be here
        function obj = rc_cleanup_sys(varargin)
            coder.allowpcode('plain');
            % Support name-value pair arguments when constructing the object.
            setProperties(obj,nargin,varargin{:});
        end
    end

    methods (Access = protected)

        function releaseImpl(obj) % Termination code
             if coder.target('Rtw') %  Generated Code: call external output code
                coder.ceval('rc_cleanup');
                disp(['Rtw - Cleaned up?']);

             elseif coder.target('MATLAB') % Simulaion: display values
               %Don't do anything in Matlab interpretive mode
               disp(['MATLAB - Cleanup step']);
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
            icon = 'rc_cleanup_sys';
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
            name = 'rc_cleanup';
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
