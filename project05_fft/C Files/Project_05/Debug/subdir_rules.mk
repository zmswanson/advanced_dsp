################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
aic3204.obj: ../aic3204.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv6/tools/compiler/c5500_4.4.1/bin/cl55" -v5515 --memory_model=large -O3 -g --include_path="C:/ti/ccsv6/tools/compiler/c5500_4.4.1/include" --include_path="C:/Users/Zach/Dropbox/elec498_spring_2018/c55_dsplib_03.00.00.03/include" --include_path="C:/Users/Zach/Dropbox/elec498_spring_2018/ezdsp5535_v1/c55xx_csl/inc" --include_path="C:/Users/Zach/Dropbox/elec498_spring_2018/ezdsp5535_v1/include" --include_path="C:/Users/Zach/Desktop/498 DSP/Project 05 - FFT/C Files/Project_05/Debug" --include_path="C:/ti/bios_5_42_01_09/packages/ti/bios/include" --include_path="C:/ti/bios_5_42_01_09/packages/ti/rtdx/include/c5500" --define=c5535 --display_error_number --diag_warning=225 --ptrdiff_size=16 --preproc_with_compile --preproc_dependency="aic3204.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

audioProcessing.obj: ../audioProcessing.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv6/tools/compiler/c5500_4.4.1/bin/cl55" -v5515 --memory_model=large -O3 -g --include_path="C:/ti/ccsv6/tools/compiler/c5500_4.4.1/include" --include_path="C:/Users/Zach/Dropbox/elec498_spring_2018/c55_dsplib_03.00.00.03/include" --include_path="C:/Users/Zach/Dropbox/elec498_spring_2018/ezdsp5535_v1/c55xx_csl/inc" --include_path="C:/Users/Zach/Dropbox/elec498_spring_2018/ezdsp5535_v1/include" --include_path="C:/Users/Zach/Desktop/498 DSP/Project 05 - FFT/C Files/Project_05/Debug" --include_path="C:/ti/bios_5_42_01_09/packages/ti/bios/include" --include_path="C:/ti/bios_5_42_01_09/packages/ti/rtdx/include/c5500" --define=c5535 --display_error_number --diag_warning=225 --ptrdiff_size=16 --preproc_with_compile --preproc_dependency="audioProcessing.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

cbrev.obj: ../cbrev.asm $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv6/tools/compiler/c5500_4.4.1/bin/cl55" -v5515 --memory_model=large -O3 -g --include_path="C:/ti/ccsv6/tools/compiler/c5500_4.4.1/include" --include_path="C:/Users/Zach/Dropbox/elec498_spring_2018/c55_dsplib_03.00.00.03/include" --include_path="C:/Users/Zach/Dropbox/elec498_spring_2018/ezdsp5535_v1/c55xx_csl/inc" --include_path="C:/Users/Zach/Dropbox/elec498_spring_2018/ezdsp5535_v1/include" --include_path="C:/Users/Zach/Desktop/498 DSP/Project 05 - FFT/C Files/Project_05/Debug" --include_path="C:/ti/bios_5_42_01_09/packages/ti/bios/include" --include_path="C:/ti/bios_5_42_01_09/packages/ti/rtdx/include/c5500" --define=c5535 --display_error_number --diag_warning=225 --ptrdiff_size=16 --preproc_with_compile --preproc_dependency="cbrev.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

cfft_noscale.obj: ../cfft_noscale.asm $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv6/tools/compiler/c5500_4.4.1/bin/cl55" -v5515 --memory_model=large -O3 -g --include_path="C:/ti/ccsv6/tools/compiler/c5500_4.4.1/include" --include_path="C:/Users/Zach/Dropbox/elec498_spring_2018/c55_dsplib_03.00.00.03/include" --include_path="C:/Users/Zach/Dropbox/elec498_spring_2018/ezdsp5535_v1/c55xx_csl/inc" --include_path="C:/Users/Zach/Dropbox/elec498_spring_2018/ezdsp5535_v1/include" --include_path="C:/Users/Zach/Desktop/498 DSP/Project 05 - FFT/C Files/Project_05/Debug" --include_path="C:/ti/bios_5_42_01_09/packages/ti/bios/include" --include_path="C:/ti/bios_5_42_01_09/packages/ti/rtdx/include/c5500" --define=c5535 --display_error_number --diag_warning=225 --ptrdiff_size=16 --preproc_with_compile --preproc_dependency="cfft_noscale.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

cfft_scale.obj: ../cfft_scale.asm $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv6/tools/compiler/c5500_4.4.1/bin/cl55" -v5515 --memory_model=large -O3 -g --include_path="C:/ti/ccsv6/tools/compiler/c5500_4.4.1/include" --include_path="C:/Users/Zach/Dropbox/elec498_spring_2018/c55_dsplib_03.00.00.03/include" --include_path="C:/Users/Zach/Dropbox/elec498_spring_2018/ezdsp5535_v1/c55xx_csl/inc" --include_path="C:/Users/Zach/Dropbox/elec498_spring_2018/ezdsp5535_v1/include" --include_path="C:/Users/Zach/Desktop/498 DSP/Project 05 - FFT/C Files/Project_05/Debug" --include_path="C:/ti/bios_5_42_01_09/packages/ti/bios/include" --include_path="C:/ti/bios_5_42_01_09/packages/ti/rtdx/include/c5500" --define=c5535 --display_error_number --diag_warning=225 --ptrdiff_size=16 --preproc_with_compile --preproc_dependency="cfft_scale.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

ezdsp5535_i2c.obj: ../ezdsp5535_i2c.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv6/tools/compiler/c5500_4.4.1/bin/cl55" -v5515 --memory_model=large -O3 -g --include_path="C:/ti/ccsv6/tools/compiler/c5500_4.4.1/include" --include_path="C:/Users/Zach/Dropbox/elec498_spring_2018/c55_dsplib_03.00.00.03/include" --include_path="C:/Users/Zach/Dropbox/elec498_spring_2018/ezdsp5535_v1/c55xx_csl/inc" --include_path="C:/Users/Zach/Dropbox/elec498_spring_2018/ezdsp5535_v1/include" --include_path="C:/Users/Zach/Desktop/498 DSP/Project 05 - FFT/C Files/Project_05/Debug" --include_path="C:/ti/bios_5_42_01_09/packages/ti/bios/include" --include_path="C:/ti/bios_5_42_01_09/packages/ti/rtdx/include/c5500" --define=c5535 --display_error_number --diag_warning=225 --ptrdiff_size=16 --preproc_with_compile --preproc_dependency="ezdsp5535_i2c.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

ezdsp5535_lcd.obj: ../ezdsp5535_lcd.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv6/tools/compiler/c5500_4.4.1/bin/cl55" -v5515 --memory_model=large -O3 -g --include_path="C:/ti/ccsv6/tools/compiler/c5500_4.4.1/include" --include_path="C:/Users/Zach/Dropbox/elec498_spring_2018/c55_dsplib_03.00.00.03/include" --include_path="C:/Users/Zach/Dropbox/elec498_spring_2018/ezdsp5535_v1/c55xx_csl/inc" --include_path="C:/Users/Zach/Dropbox/elec498_spring_2018/ezdsp5535_v1/include" --include_path="C:/Users/Zach/Desktop/498 DSP/Project 05 - FFT/C Files/Project_05/Debug" --include_path="C:/ti/bios_5_42_01_09/packages/ti/bios/include" --include_path="C:/ti/bios_5_42_01_09/packages/ti/rtdx/include/c5500" --define=c5535 --display_error_number --diag_warning=225 --ptrdiff_size=16 --preproc_with_compile --preproc_dependency="ezdsp5535_lcd.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

fftDisplay.obj: ../fftDisplay.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv6/tools/compiler/c5500_4.4.1/bin/cl55" -v5515 --memory_model=large -O3 -g --include_path="C:/ti/ccsv6/tools/compiler/c5500_4.4.1/include" --include_path="C:/Users/Zach/Dropbox/elec498_spring_2018/c55_dsplib_03.00.00.03/include" --include_path="C:/Users/Zach/Dropbox/elec498_spring_2018/ezdsp5535_v1/c55xx_csl/inc" --include_path="C:/Users/Zach/Dropbox/elec498_spring_2018/ezdsp5535_v1/include" --include_path="C:/Users/Zach/Desktop/498 DSP/Project 05 - FFT/C Files/Project_05/Debug" --include_path="C:/ti/bios_5_42_01_09/packages/ti/bios/include" --include_path="C:/ti/bios_5_42_01_09/packages/ti/rtdx/include/c5500" --define=c5535 --display_error_number --diag_warning=225 --ptrdiff_size=16 --preproc_with_compile --preproc_dependency="fftDisplay.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

hellocfg.cmd: ../hello.tcf
	@echo 'Building file: $<'
	@echo 'Invoking: TConf'
	"C:/ti/bios_5_42_01_09/xdctools/tconf" -b -Dconfig.importPath="C:/ti/bios_5_42_01_09/packages;" "$<"
	@echo 'Finished building: $<'
	@echo ' '

hellocfg.s??: | hellocfg.cmd
hellocfg_c.c: | hellocfg.cmd
hellocfg.h: | hellocfg.cmd
hellocfg.h??: | hellocfg.cmd
hello.cdb: | hellocfg.cmd

hellocfg.obj: ./hellocfg.s?? $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv6/tools/compiler/c5500_4.4.1/bin/cl55" -v5515 --memory_model=large -O3 -g --include_path="C:/ti/ccsv6/tools/compiler/c5500_4.4.1/include" --include_path="C:/Users/Zach/Dropbox/elec498_spring_2018/c55_dsplib_03.00.00.03/include" --include_path="C:/Users/Zach/Dropbox/elec498_spring_2018/ezdsp5535_v1/c55xx_csl/inc" --include_path="C:/Users/Zach/Dropbox/elec498_spring_2018/ezdsp5535_v1/include" --include_path="C:/Users/Zach/Desktop/498 DSP/Project 05 - FFT/C Files/Project_05/Debug" --include_path="C:/ti/bios_5_42_01_09/packages/ti/bios/include" --include_path="C:/ti/bios_5_42_01_09/packages/ti/rtdx/include/c5500" --define=c5535 --display_error_number --diag_warning=225 --ptrdiff_size=16 --preproc_with_compile --preproc_dependency="hellocfg.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

hellocfg_c.obj: ./hellocfg_c.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv6/tools/compiler/c5500_4.4.1/bin/cl55" -v5515 --memory_model=large -O3 -g --include_path="C:/ti/ccsv6/tools/compiler/c5500_4.4.1/include" --include_path="C:/Users/Zach/Dropbox/elec498_spring_2018/c55_dsplib_03.00.00.03/include" --include_path="C:/Users/Zach/Dropbox/elec498_spring_2018/ezdsp5535_v1/c55xx_csl/inc" --include_path="C:/Users/Zach/Dropbox/elec498_spring_2018/ezdsp5535_v1/include" --include_path="C:/Users/Zach/Desktop/498 DSP/Project 05 - FFT/C Files/Project_05/Debug" --include_path="C:/ti/bios_5_42_01_09/packages/ti/bios/include" --include_path="C:/ti/bios_5_42_01_09/packages/ti/rtdx/include/c5500" --define=c5535 --display_error_number --diag_warning=225 --ptrdiff_size=16 --preproc_with_compile --preproc_dependency="hellocfg_c.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

main.obj: ../main.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv6/tools/compiler/c5500_4.4.1/bin/cl55" -v5515 --memory_model=large -O3 -g --include_path="C:/ti/ccsv6/tools/compiler/c5500_4.4.1/include" --include_path="C:/Users/Zach/Dropbox/elec498_spring_2018/c55_dsplib_03.00.00.03/include" --include_path="C:/Users/Zach/Dropbox/elec498_spring_2018/ezdsp5535_v1/c55xx_csl/inc" --include_path="C:/Users/Zach/Dropbox/elec498_spring_2018/ezdsp5535_v1/include" --include_path="C:/Users/Zach/Desktop/498 DSP/Project 05 - FFT/C Files/Project_05/Debug" --include_path="C:/ti/bios_5_42_01_09/packages/ti/bios/include" --include_path="C:/ti/bios_5_42_01_09/packages/ti/rtdx/include/c5500" --define=c5535 --display_error_number --diag_warning=225 --ptrdiff_size=16 --preproc_with_compile --preproc_dependency="main.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

myNCO.obj: ../myNCO.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv6/tools/compiler/c5500_4.4.1/bin/cl55" -v5515 --memory_model=large -O3 -g --include_path="C:/ti/ccsv6/tools/compiler/c5500_4.4.1/include" --include_path="C:/Users/Zach/Dropbox/elec498_spring_2018/c55_dsplib_03.00.00.03/include" --include_path="C:/Users/Zach/Dropbox/elec498_spring_2018/ezdsp5535_v1/c55xx_csl/inc" --include_path="C:/Users/Zach/Dropbox/elec498_spring_2018/ezdsp5535_v1/include" --include_path="C:/Users/Zach/Desktop/498 DSP/Project 05 - FFT/C Files/Project_05/Debug" --include_path="C:/ti/bios_5_42_01_09/packages/ti/bios/include" --include_path="C:/ti/bios_5_42_01_09/packages/ti/rtdx/include/c5500" --define=c5535 --display_error_number --diag_warning=225 --ptrdiff_size=16 --preproc_with_compile --preproc_dependency="myNCO.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

myfir.obj: ../myfir.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv6/tools/compiler/c5500_4.4.1/bin/cl55" -v5515 --memory_model=large -O3 -g --include_path="C:/ti/ccsv6/tools/compiler/c5500_4.4.1/include" --include_path="C:/Users/Zach/Dropbox/elec498_spring_2018/c55_dsplib_03.00.00.03/include" --include_path="C:/Users/Zach/Dropbox/elec498_spring_2018/ezdsp5535_v1/c55xx_csl/inc" --include_path="C:/Users/Zach/Dropbox/elec498_spring_2018/ezdsp5535_v1/include" --include_path="C:/Users/Zach/Desktop/498 DSP/Project 05 - FFT/C Files/Project_05/Debug" --include_path="C:/ti/bios_5_42_01_09/packages/ti/bios/include" --include_path="C:/ti/bios_5_42_01_09/packages/ti/rtdx/include/c5500" --define=c5535 --display_error_number --diag_warning=225 --ptrdiff_size=16 --preproc_with_compile --preproc_dependency="myfir.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

twiddle.obj: ../twiddle.asm $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv6/tools/compiler/c5500_4.4.1/bin/cl55" -v5515 --memory_model=large -O3 -g --include_path="C:/ti/ccsv6/tools/compiler/c5500_4.4.1/include" --include_path="C:/Users/Zach/Dropbox/elec498_spring_2018/c55_dsplib_03.00.00.03/include" --include_path="C:/Users/Zach/Dropbox/elec498_spring_2018/ezdsp5535_v1/c55xx_csl/inc" --include_path="C:/Users/Zach/Dropbox/elec498_spring_2018/ezdsp5535_v1/include" --include_path="C:/Users/Zach/Desktop/498 DSP/Project 05 - FFT/C Files/Project_05/Debug" --include_path="C:/ti/bios_5_42_01_09/packages/ti/bios/include" --include_path="C:/ti/bios_5_42_01_09/packages/ti/rtdx/include/c5500" --define=c5535 --display_error_number --diag_warning=225 --ptrdiff_size=16 --preproc_with_compile --preproc_dependency="twiddle.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

unpack.obj: ../unpack.asm $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv6/tools/compiler/c5500_4.4.1/bin/cl55" -v5515 --memory_model=large -O3 -g --include_path="C:/ti/ccsv6/tools/compiler/c5500_4.4.1/include" --include_path="C:/Users/Zach/Dropbox/elec498_spring_2018/c55_dsplib_03.00.00.03/include" --include_path="C:/Users/Zach/Dropbox/elec498_spring_2018/ezdsp5535_v1/c55xx_csl/inc" --include_path="C:/Users/Zach/Dropbox/elec498_spring_2018/ezdsp5535_v1/include" --include_path="C:/Users/Zach/Desktop/498 DSP/Project 05 - FFT/C Files/Project_05/Debug" --include_path="C:/ti/bios_5_42_01_09/packages/ti/bios/include" --include_path="C:/ti/bios_5_42_01_09/packages/ti/rtdx/include/c5500" --define=c5535 --display_error_number --diag_warning=225 --ptrdiff_size=16 --preproc_with_compile --preproc_dependency="unpack.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


