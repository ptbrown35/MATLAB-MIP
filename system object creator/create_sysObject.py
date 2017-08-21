"""
Filename: create_sysObject.py
Last Modified: August 20, 2017
Author: Parker Brown <ptbrown@ucsd.edu>
Description: Create a MATLAB Simulink System Object to be used with Beaglebone
             Black/Blue Roboticscape Library
"""

def test():
    filename = "rc_set_led"
    description = "Set LED function block"
    tunable = True
    nontunable = False
    propName =  "led"
    prop = "1"
    
    return create(filename, description, tunable, nontunable, propName, prop)


#%%

def create(filename, description, tunable, nontunable, propName, prop):
    file = open(filename + "_sys.m", "w")
    file.write(header(filename, description))
    file.write(classdef(filename, tunable, nontunable))
    file.write(properties(tunable, nontunable, propName, prop))
    file.write(constructor(filename))
    file.write(stepImpl(filename, propName))
    file.write(propDef(filename))
    file.write(eof(filename))
    
    return 1

#%% header

def header(filename, description):
    text  = "% Filename: " + filename + "_sys.m\n"
    text += "% Last Modified: August 20, 2017\n"
    text += "% Author: Parker Brown <ptbrown@ucsd.edu>\n"
    text += "% Description: " + description + "\n"
    text += "\n"
    
    return text

#%% classdef

def classdef(filename, tunable, nontunable):
    text = "\
classdef rc_set_led_sys < matlab.System ...\n\
        & coder.ExternalDependency ...\n\
        & matlab.system.mixin.CustomIcon ...\n"
    if tunable or nontunable:
        text += "        & matlab.system.mixin.Propagates\n"
    text += "\n"
    
    return text

#%% Setup: Properties

def properties(tunable, nontunable, propName, prop):
    
    if nontunable:
        text = "\
    properties(Nontunable) % Private, nontunable properties\n\
        "+ propName + " = " + prop + "\n\
    end\n\
    \n"
    elif tunable:
        text = "\
    properties % Public, tunable properties\n\
        "+ propName + " = " + prop + "\n\
    end\n\
    \n"
    else:
        text = "\
    properties % Public, tunable properties\n\
        \n\
    end\n\
    \n"
    
    return text


#%% Setup: Constructor

def constructor(filename):
    text = "\
    methods\n\
        % Constructor : this must be here\n\
        function obj = " + filename + "_sys(varargin)\n\
            coder.allowpcode('plain');\n\
            % Support name-value pair arguments when constructing the object.\n\
            setProperties(obj,nargin,varargin{:});\n\
        end\n\
    end\n\
    \n"
    
    return text

#%% stepImpl

# make this modular somehow... right now just 1 input, one output

def stepImpl(filename, propName):
    
    text = "\
    methods (Access = protected)\n\
        \n\
        function y = stepImpl(obj,u) % Implement step\n\
            \n\
            y = int8(0);\n\
            if coder.target('Rtw') %  Generated Code: call external output code\n\
                y = coder.ceval('" + filename + "', obj." + propName + ", u);\n\
                disp('Rtw - " + filename + "');\n\
            elseif coder.target('MATLAB') % Simulation\n\
                disp(['MATLAB - Step: Input = ' num2str(u)]);\n\
            end\n\
        end\n\
    end\n\
    \n"
    
    return text

#%% Input/Output property definitions

# make this modular somehow... right now just 1 input, one output

def propDef(filename):
    
    text = "\
    methods (Access = protected)\n\
        %% Define input properties\n\
        function num = getNumInputsImpl(~)\n\
            num = 1;\n\
        end\n\
        \n\
        function num = getNumOutputsImpl(~)\n\
            num = 1;\n\
        end\n\
        \n\
        function varargout = getInputNamesImpl(~)\n\
            varargout{1} = 'u';\n\
        end\n\
        \n\
        function varargout = getOutputNamesImpl(~)\n\
            varargout{1} = 'y';\n\
        end\n\
        \n\
        function flag = isInputSizeLockedImpl(~,~)\n\
            flag = true;\n\
        end\n\
        \n\
        function flag = isOutputSizeLockedImpl(~,~)\n\
            flag = true;\n\
        end\n\
        \n\
        function varargout = isInputFixedSizeImpl(~,~)\n\
            varargout{1} = true;\n\
        end\n\
        \n\
        function varargout = isOutputFixedSizeImpl(~,~)\n\
            varargout{1} = true;\n\
        end\n\
        \n\
        function flag = isInputComplexityLockedImpl(~,~)\n\
            flag = true;\n\
        end\n\
        \n\
        function flag = isOutputComplexityLockedImpl(~,~)\n\
            flag = true;\n\
        end\n\
        \n\
        function varargout = isInputComplexImpl(~)\n\
            varargout{1} = false;\n\
        end\n\
        \n\
        function varargout = isOutputComplexImpl(~)\n\
            varargout{1} = false;\n\
        end\n\
        \n\
        function sz_1 = getOutputSizeImpl(~)\n\
            sz_1 = [1 1];\n\
        end\n\
        \n\
        function out = getOutputDataTypeImpl(~)\n\
            out = 'int8';\n\
        end\n\
        \n\
        function validateInputsImpl(~, u)\n\
            if isempty(coder.target)\n\
                % Run this always in Simulation\n\
                validateattributes(u,{'uint8','uint16','uint32','uint64', ...\n\
                    'int8','int16','int32','int64','single','double'}, ...\n\
                    {'scalar','>=',0,'<=',255'},'','input');\n\
            end\n\
        end\n\
        \n\
        function validateOutputsImpl(~, y)\n\
            if isempty(coder.target)\n\
                % Run this always in Simulation\n\
                validateattributes(y,{'uint8','uint16','uint32','uint64', ...\n\
                    'int8','int16','int32','int64','single','double'}, ...\n\
                    {'scalar','>=',-128,'<=',127'},'','output');\n\
            end\n\
        end\n\
        \n\
        function icon = getIconImpl(~)\n\
            % Define a string as the icon for the System block in Simulink.\n\
            icon = '" + filename + "_sys';\n\
        end\n\
    end\n\
    \n"
    
    return text

#%% end of file
# All System Objects will end with this chunch of code

def eof(filename):
    text = "\
    methods (Static, Access = protected)\n\
        function simMode = getSimulateUsingImpl(~)\n\
            simMode = 'Interpreted execution';\n\
        end\n\
        \n\
        function isVisible = showSimulateUsingImpl\n\
            isVisible = false;\n\
        end\n\
    end\n\
    \n\
    methods (Static)\n\
        \n\
        function name = getDescriptiveName()\n\
            name = '"
    text += filename
    text += "';\n\
        end\n\
        \n\
        function b = isSupportedContext(context)\n\
            b = context.isCodeGenTarget('rtw');\n\
        end\n\
        \n\
        function updateBuildInfo(buildInfo, context)\n\
            if context.isCodeGenTarget('rtw')\n\
                % Update buildInfo\n\
                rootDir = fullfile(fileparts(mfilename('fullpath')),'.');\n\
                buildInfo.addIncludePaths(rootDir);\n\
                buildInfo.addLinkFlags('-lroboticscape');\n\
            end\n\
        end\n\
    end\n\
end\n\
\n"
    
    return text

#%%

