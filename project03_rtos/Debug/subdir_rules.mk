################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
aic3204.obj: ../aic3204.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv6/tools/compiler/c5500_4.4.1/bin/cl55" -v5515 --memory_model=large -O3 -g --include_path="C:/ti/ccsv6/tools/compiler/c5500_4.4.1/include" --include_path="C:/Users/Zach/Dropbox/elec498_spring_2018/ezdsp5535_v1/c55xx_csl/inc" --include_path="C:/Users/Zach/Dropbox/elec498_spring_2018/ezdsp5535_v1/include" --include_path="C:/Users/Zach/workspace_v6_1/Project3_v2/Debug" --include_path="C:/ti/bios_5_42_01_09/packages/ti/bios/include" --include_path="C:/ti/bios_5_42_01_09/packages/ti/rtdx/include/c5500" --define=c5535 --display_error_number --diag_warning=225 --ptrdiff_size=16 --preproc_with_compile --preproc_dependency="aic3204.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

audioProcessing.obj: ../audioProcessing.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv6/tools/compiler/c5500_4.4.1/bin/cl55" -v5515 --memory_model=large -O3 -g --include_path="C:/ti/ccsv6/tools/compiler/c5500_4.4.1/include" --include_path="C:/Users/Zach/Dropbox/elec498_spring_2018/ezdsp5535_v1/c55xx_csl/inc" --include_path="C:/Users/Zach/Dropbox/elec498_spring_2018/ezdsp5535_v1/include" --include_path="C:/Users/Zach/workspace_v6_1/Project3_v2/Debug" --include_path="C:/ti/bios_5_42_01_09/packages/ti/bios/include" --include_path="C:/ti/bios_5_42_01_09/packages/ti/rtdx/include/c5500" --define=c5535 --display_error_number --diag_warning=225 --ptrdiff_size=16 --preproc_with_compile --preproc_dependency="audioProcessing.pp" $(GEN_OPTS__FLAG) "$<"
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
	"C:/ti/ccsv6/tools/compiler/c5500_4.4.1/bin/cl55" -v5515 --memory_model=large -O3 -g --include_path="C:/ti/ccsv6/tools/compiler/c5500_4.4.1/include" --include_path="C:/Users/Zach/Dropbox/elec498_spring_2018/ezdsp5535_v1/c55xx_csl/inc" --include_path="C:/Users/Zach/Dropbox/elec498_spring_2018/ezdsp5535_v1/include" --include_path="C:/Users/Zach/workspace_v6_1/Project3_v2/Debug" --include_path="C:/ti/bios_5_42_01_09/packages/ti/bios/include" --include_path="C:/ti/bios_5_42_01_09/packages/ti/rtdx/include/c5500" --define=c5535 --display_error_number --diag_warning=225 --ptrdiff_size=16 --preproc_with_compile --preproc_dependency="hellocfg.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

hellocfg_c.obj: ./hellocfg_c.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv6/tools/compiler/c5500_4.4.1/bin/cl55" -v5515 --memory_model=large -O3 -g --include_path="C:/ti/ccsv6/tools/compiler/c5500_4.4.1/include" --include_path="C:/Users/Zach/Dropbox/elec498_spring_2018/ezdsp5535_v1/c55xx_csl/inc" --include_path="C:/Users/Zach/Dropbox/elec498_spring_2018/ezdsp5535_v1/include" --include_path="C:/Users/Zach/workspace_v6_1/Project3_v2/Debug" --include_path="C:/ti/bios_5_42_01_09/packages/ti/bios/include" --include_path="C:/ti/bios_5_42_01_09/packages/ti/rtdx/include/c5500" --define=c5535 --display_error_number --diag_warning=225 --ptrdiff_size=16 --preproc_with_compile --preproc_dependency="hellocfg_c.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

main.obj: ../main.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv6/tools/compiler/c5500_4.4.1/bin/cl55" -v5515 --memory_model=large -O3 -g --include_path="C:/ti/ccsv6/tools/compiler/c5500_4.4.1/include" --include_path="C:/Users/Zach/Dropbox/elec498_spring_2018/ezdsp5535_v1/c55xx_csl/inc" --include_path="C:/Users/Zach/Dropbox/elec498_spring_2018/ezdsp5535_v1/include" --include_path="C:/Users/Zach/workspace_v6_1/Project3_v2/Debug" --include_path="C:/ti/bios_5_42_01_09/packages/ti/bios/include" --include_path="C:/ti/bios_5_42_01_09/packages/ti/rtdx/include/c5500" --define=c5535 --display_error_number --diag_warning=225 --ptrdiff_size=16 --preproc_with_compile --preproc_dependency="main.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

myNCO.obj: ../myNCO.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv6/tools/compiler/c5500_4.4.1/bin/cl55" -v5515 --memory_model=large -O3 -g --include_path="C:/ti/ccsv6/tools/compiler/c5500_4.4.1/include" --include_path="C:/Users/Zach/Dropbox/elec498_spring_2018/ezdsp5535_v1/c55xx_csl/inc" --include_path="C:/Users/Zach/Dropbox/elec498_spring_2018/ezdsp5535_v1/include" --include_path="C:/Users/Zach/workspace_v6_1/Project3_v2/Debug" --include_path="C:/ti/bios_5_42_01_09/packages/ti/bios/include" --include_path="C:/ti/bios_5_42_01_09/packages/ti/rtdx/include/c5500" --define=c5535 --display_error_number --diag_warning=225 --ptrdiff_size=16 --preproc_with_compile --preproc_dependency="myNCO.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

myfir.obj: ../myfir.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv6/tools/compiler/c5500_4.4.1/bin/cl55" -v5515 --memory_model=large -O3 -g --include_path="C:/ti/ccsv6/tools/compiler/c5500_4.4.1/include" --include_path="C:/Users/Zach/Dropbox/elec498_spring_2018/ezdsp5535_v1/c55xx_csl/inc" --include_path="C:/Users/Zach/Dropbox/elec498_spring_2018/ezdsp5535_v1/include" --include_path="C:/Users/Zach/workspace_v6_1/Project3_v2/Debug" --include_path="C:/ti/bios_5_42_01_09/packages/ti/bios/include" --include_path="C:/ti/bios_5_42_01_09/packages/ti/rtdx/include/c5500" --define=c5535 --display_error_number --diag_warning=225 --ptrdiff_size=16 --preproc_with_compile --preproc_dependency="myfir.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


