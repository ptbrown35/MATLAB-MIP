classdef bbblueDCMotor < matlab.System ...
        &  matlab.system.mixin.internal.CustomIcon & matlab.system.mixin.Propagates...
        & coder.ExternalDependency
    % Untitled2 Add summary here
    %
    % This template includes the minimum set of functions required
    % to define a System object with discrete state.
    
    %#codegen
    %#ok<*EMCA>
    properties(Nontunable)
        %Motor Index
        index = '1';
        %Stop action
        stopaction = 'Brake';
    end
    
    properties(Constant, Hidden)
        indexSet = matlab.system.StringSet({'1','2','3','4'})
        stopactionSet = matlab.system.StringSet({'Brake','Free Spin'});
        blockPlatform = 'BB BLUE'
    end
    
    properties(Hidden)
        indexEnum
        actionEnum
    end
    
    methods
        % Constructor
        function obj = bbblueDCMotor(varargin)
            %This would allow the code generation to proceed with the
            %p-files in the installed location of the support package.
            coder.allowpcode('plain');            
            % Support name-value pair arguments when constructing the object.
            setProperties(obj,nargin,varargin{:});
        end
        
        
        
        function indexval = get.indexEnum(obj)
            switch(obj.index)
                case '1'
                    indexval = uint8(1);
                case '2'
                    indexval = uint8(2);
                case '3'
                    indexval = uint8(3);
                case '4'
                    indexval = unit8(4);
            end
        end
        
        function actionval = get.actionEnum(obj)
            switch(obj.stopaction)
                case 'Brake'
                    actionval = uint8(1);                
                case 'Free Spin'
                    actionval = uint8(2);
            end
        end
    end
    
    methods(Access = protected)
        function setupImpl(~)
            % Perform one-time calculations, such as computing constants
            if coder.target('Rtw')
                coder.cinclude('MW_bbblue_driver.h');coder.updateBuildInfo('addDefines','_roboticscape_in_use_');
                coder.updateBuildInfo('addDefines','_RTT_DCMOTOR_INUSE_');                
            end
        end
        
        function validateInputsImpl(~, u)
                 validateattributes(u, {'int8'}, ...
                {'scalar', 'real', 'nonnan', 'finite','integer'}, '', 'dutyCycle');    
        end
        
        
        function stepImpl(obj,duty)
            % Implement algorithm. Calculate y as a function of input u and
            %  discrete states.
            if coder.target('Rtw')                
                   coder.ceval('MW_set_motor',obj.indexEnum,duty,obj.actionEnum);               
            end
        end
        
        function releaseImpl(obj)
            % Release resources, such as file handles
            if coder.target('Rtw')
                coder.ceval('MW_terminate_motor',obj.actionEnum);
            end
        end
        
        function num = getNumInputsImpl(~)
            % Define total number of inputs for system with optional inputs
            num = 1;
            % if obj.UseOptionalInput
            %     num = 2;
            % end
        end
        
        function num = getNumOutputsImpl(~)
            % Define total number of outputs for system with optional
            % outputs
            num = 0;
        end
        
        
        
        function maskDisplayCmds = getMaskDisplayImpl(obj)
            Motorindex = ['Motor index : ' obj.index];
            blockName = 'DC Motor';
            maskDisplayCmds = [ ...
                ['color(''white'');',newline]...
                ['plot([100,100,100,100]*1,[100,100,100,100]*1);',newline]...
                ['plot([100,100,100,100]*0,[100,100,100,100]*0);',newline]...                
                ['color(''blue'');',newline] ...
                ['text(100, 92, '' ' obj.blockPlatform ' '', ''horizontalAlignment'', ''right'');',newline]  ...
                ['color(''black'');',newline]...
                ['text(52,12,' [''' ' Motorindex ''',''horizontalAlignment'',''center'');' newline]]   ...
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
                    addSourceFiles(buildInfo, 'MW_bbblue_dcmotor.c', fullfile(spkgRootDir, 'src'), 'BlockModules');
                end
                
            end
        end
    end %methods
    
    methods(Access = protected, Static)
        function header = getHeaderImpl
            % Define header panel for System block dialog
               header = matlab.system.display.Header(mfilename('class'), ...
                'Title', 'DC Motor', ...
                'Text',['Control the power and direction of the DC motor on the selected channel' newline newline ...
                'The block input accepts integrs from 100 to -100:' newline ...
                '* 100 = Full power forward' newline ...
                '* 0 = No power' newline ...
                '* -100 = Full power reverse' newline newline ...
                'Use the Motor Index dropdown to select the index of the BeagleBone Blue DC motor port that is connected to the motor.' ...
                newline 'Use the Stop Action drop down to set the beahviour when the motor stops.'], ...
                'ShowSourceLink', false);
        end
        
        function flag = showSimulateUsingImpl
            % Return false if simulation mode hidden in System block dialog
            flag = false;
        end
    end
end
