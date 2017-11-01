classdef bbblueIMU < matlab.System ...
        & matlab.system.mixin.internal.CustomIcon ...
        & matlab.system.mixin.Propagates ...
        & matlabshared.svd.BlockSampleTime ...
        & coder.ExternalDependency
    
    % Beaglebone Blue IMU
    %
    % This template includes the minimum set of functions required
    % to define a System object with discrete state.
    
    %#codegen
    %#ok<*EMCA>
    
    properties(Nontunable)
        
    end
    
    properties(Constant, Hidden)
        blockPlatform = 'BB BLUE'
    end
    
    properties(Hidden)
%         conf = struct();
%         data = struct();
    end
    
    methods
        % Constructor
        function obj = bbblueIMU(varargin)
            %This would allow the code generation to proceed with the
            %p-files in the installed location of the support package.
            coder.allowpcode('plain');            
            % Support name-value pair arguments when constructing the object.
            setProperties(obj,nargin,varargin{:});
        end
        
    end
    
    methods(Access = protected)
        function setupImpl(obj)
            % Perform one-time calculations, such as computing constants
            if coder.target('Rtw')
                coder.cinclude('MW_bbblue_driver.h');
                coder.updateBuildInfo('addDefines','_roboticscape_in_use_');
                
            % config structure declaration
                % full scale ranges for sensors
                conf.accel_fsr = coder.opaque('rc_accel_fsr_t', 'A_FSR_4G'); % AFS_2G, AFS_4G, AFS_8G, AFS_16G
                conf.gyro_fsr = coder.opaque('rc_gyro_fsr_t', 'G_FSR_1000DPS');  % GFS_250,GFS_500,GFS_1000,GFS_2000
                % internal low pass filter constants
                conf.gyro_dlpf = coder.opaque('rc_gyro_dlpf_t', 'GYRO_DLPF_92');
                conf.accel_dlpf = coder.opaque('rc_accel_dlpf_t', 'ACCEL_DLPF_92');
                % magnetometer use is optional
                conf.enable_magnetometer = coder.opaque('int','0'); % 0 or 1
                % DMP settings, only used with DMP interrupt
                conf.dmp_sample_rate = coder.opaque('int', '100');
                conf.orientation = coder.opaque('rc_imu_orientation_t', 'ORIENTATION_Z_UP'); %orientation matrix
                conf.compass_time_constant = coder.opaque('float', '5.0'); 	% time constant for filtering fused yaw
                conf.dmp_interrupt_priority = coder.opaque('int', 'sched_get_priority_max(SCHED_FIFO)-1'); % scheduler priority for handler
                conf.show_warnings = coder.opaque('int', '0');	% set to 1 to enable showing of rc_i2c_bus warnings
                
%                 obj.conf = conf;
                
                % Indicate struct name in header
                coder.cstructname(conf, 'rc_imu_config_t', 'extern', 'HeaderFile', 'roboticscape.h');
                
            % data structure declaration
                % last read sensor values in real units
                data.accel = coder.opaque('float');	% units of m/s^2
                data.gyro = coder.opaque('float');	% units of degrees/s
                data.mag = coder.opaque('float');	% units of uT
                data.temp = coder.opaque('float');  % units of degrees Celsius

                % 16 bit raw adc readings from each sensor
                data.raw_gyro = coder.opaque('int16_t');	
                data.raw_accel = coder.opaque('int16_t');

                % FSR-derived conversion ratios from raw to real units
                data.accel_to_ms2 = coder.opaque('float');	% to m/s^2
                data.gyro_to_degs = coder.opaque('float');	% to degrees/s

                % everything below this line is available in DMP mode only
                % quaternion and TaitBryan angles from DMP based on ONLY Accel/Gyro
                data.dmp_quat = coder.opaque('float');		% normalized quaternion
                data.dmp_TaitBryan = coder.opaque('float');	% radians pitch/roll/yaw X/Y/Z

                % If magnetometer is enabled in DMP mode, the following quaternion and 
                % TaitBryan angles will be available which add magnetometer data to filter
                data.fused_quat = coder.opaque('float');		% normalized quaternion
                data.fused_TaitBryan = coder.opaque('float');	% radians pitch/roll/yaw X/Y/Z
                data.compass_heading = coder.opaque('float');		% heading filtered with gyro and accel data
                data.compass_heading_raw = coder.opaque('float');	% heading in radians from magnetometer
                
%                 obj.data = data;
                
                % Indicate struct name in header
                coder.cstructname(data, 'rc_imu_data_t', 'extern', 'HeaderFile', 'roboticscape.h');
                
                coder.cstructname(data, 'rc_imu_data_t', 'extern', 'HeaderFile', 'roboticscape.h');
                coder.cstructname(conf, 'rc_imu_config_t', 'extern', 'HeaderFile', 'roboticscape.h');
                
                % Set configuration parameters to default
                obj.conf = coder.ceval('rc_set_imu_config_to_defaults'); %, coder.ref(conf))
                
                % Initialize the IMU with data and conf pointers
                coder.ceval('rc_initialize_imu', coder.ref(obj.data), coder.ref(obj.conf))
            end
        end
        
        function [accel, gyro, mag, temp] = stepImpl(obj)
            % Implement algorithm. Calculate y as a function of input u and
            %  discrete states.
            if coder.target('Rtw')
                % Read data                
                coder.ceval('rc_read_accel_data', coder.ref(obj.data));
                coder.ceval('rc_read_gyro_data', coder.ref(obj.data));
                coder.ceval('rc_read_mag_data', coder.ref(obj.data));
                coder.ceval('rc_read_imu_temp', coder.ref(obj.data));
                % Output data
                accel = obj.data.accel;
                gyro = obj.data.gyro;
                mag = obj.data.mag;
                temp = obj.data.temp;
            end
        end
        
        function releaseImpl(~)
            % Release resources, such as file handles
            if coder.target('Rtw')
                coder.ceval('rc_power_off_imu'); % Power down IMU at end of simulation
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
            num = 4;
        end

        function varargout = getOutputNamesImpl(~)
            % Return output port names for System block
            varargout{1} = 'Accel';
            varargout{2} = 'Gyro';
            varargout{3} = 'Mag';
            varargout{4} = 'Temp';
        end
        
        function varargout = getOutputSizeImpl(~)
            % Return size for each output port
            varargout{1} = [1 3];
            varargout{2} = [1 3];
            varargout{3} = [1 3];
            varargout{4} = [1 1];
        end
        
        function varargout = getOutputDataTypeImpl(~)
            % Return data type for each output port
            varargout{1} = 'double';
            varargout{2} = 'double';
            varargout{3} = 'double';
            varargout{4} = 'double';
        end
        
        function varargout = isOutputComplexImpl(~)
            % Return true for each output port with complex data
            varargout{1} = false;
            varargout{2} = false;
            varargout{3} = false;
            varargout{4} = false;
        end
        
        function varargout = isOutputFixedSizeImpl(~)
            % Return true for each output port with fixed size
            varargout{1} = true;
            varargout{2} = true;
            varargout{3} = true;
            varargout{4} = true;
        end
        
        function st = getSampleTimeImpl(obj)
            st = obj.SampleTime;
        end

        function maskDisplayCmds = getMaskDisplayImpl(obj)
            blockName = 'IMU';
            maskDisplayCmds = [ ...
                ['color(''white'');',newline]...
                ['plot([100,100,100,100]*1,[100,100,100,100]*1);',newline]...
                ['plot([100,100,100,100]*0,[100,100,100,100]*0);',newline]...                
                ['color(''blue'');',newline] ...
                ['text(100, 92, '' ' obj.blockPlatform ' '', ''horizontalAlignment'', ''right'');',newline]  ...
                ['color(''black'');',newline]...
                ['text(52,52,' [''' ' blockName ''',''horizontalAlignment'',''center'');' newline]]   ...
                ['color(''black'');',newline]...
                ];
        end
        
    end %methods
    
    methods (Static)
        function name = getDescriptiveName()
            name = 'BeagleBone Blue IMU';
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
                    %addSourcePaths(buildInfo, fullfile(spkgRootDir, 'src'));
                end
                
            end
        end
    end %methods
    
    methods(Access = protected, Static)
        function simMode = getSimulateUsingImpl(~)
            simMode = 'Interpreted execution';
        end
        
        function header = getHeaderImpl
            % Define header panel for System block dialog
               header = matlab.system.display.Header(mfilename('class'), ...
                'Title', 'IMU', ...
                'Text',['Output Accelerometer, Gyroscope, Magnetometer, and Temperature data.'], ...
                'ShowSourceLink', false);
        end
        
        function groups = getPropertyGroupsImpl
            % Sample Time
            Sampletime = matlab.system.display.internal.Property('SampleTime', 'Description', 'Sample time');
            
            PropertyListOut = {Sampletime};
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
