$COMPILER = "clang"
$SRCFILES = "main.c ./core/AGLCore.c ./core/AGLBinding.c ./core/AGLBuffer.c ./core/AGLShader.c"
$OUTPUTFILE = "a.exe"

$LIBS = "-lgdi32 -lopengl32"

$LINTFLAGS = "-Wall -Werror -Wextra"
$OPTFLAGS = "-DNDEBUG -Os -s -fno-ident -fno-unroll-loops -fmerge-all-constants -fwrapv -fomit-frame-pointer -ffunction-sections -fdata-sections -fno-asynchronous-unwind-tables"
$EXTROPT = "strip ./a.exe && C:\Users\Maksims Turs\Downloads\upx-4.2.4-win64\upx-4.2.4-win64\upx.exe --best --ultra-brute a.exe"

$COMMAND = "$COMPILER $SRCFILES $LIBS $LINTFLAGS -o $OUTPUTFILE"
# $COMMAND = "$COMPILER $SRCFILES $LIBS $LINTFLAGS $OPTFLAGS -o $OUTPUTFILE && $EXTROPT"

Write-Host "Compiling..."
Invoke-Expression $COMMAND

if ($?) {
    Write-Host "Successfuly compiled, runing the programm..."
    & .\$OUTPUTFILE
} else {
    Write-Host "Error by compiling programm..."
}
