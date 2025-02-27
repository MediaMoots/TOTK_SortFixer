@echo off

:: User configuration has moved to misc\mk\config.mk.

:: Make arguments.
set MAKE_ARGS=-j8 V=1

:: Determine the make verb from the user action.
if "%1" == "build" (
    set MAKE_VERB=
    goto :CONTINUE
) else if "%1" == "clean" (
    set MAKE_VERB=clean
    goto :CONTINUE
) else if "%1" == "deploy-sd" (
    set MAKE_VERB=deploy-sd
    goto :CONTINUE
) else if "%1" == "deploy-ftp" (
    set MAKE_VERB=deploy-ftp
    goto :CONTINUE
) else if "%1" == "deploy-ryu" (
    set MAKE_VERB=deploy-ryu
    goto :CONTINUE
) else if "%1" == "make-npdm-json" (
    set MAKE_VERB=npdm-json
    goto :CONTINUE
) else (
    set MAKE_VERB=build
)

:CONTINUE

:: Run the make command.
make %MAKE_ARGS% %MAKE_VERB%
