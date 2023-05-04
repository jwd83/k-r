# a script to build all the C files in this directory with clang

$files = Get-ChildItem -Path . -Filter *.c

foreach ($file in $files) {
    $name = $file.Name
    $name = $name.Substring(0, $name.Length - 2)
    $x86name = $name + "-x86.exe"
    $x64name = $name + "-x64.exe"
    clang  -m32 -Oz -o $x86name $file
    clang  -m64 -Oz -o $x64name $file
}

dir *.exe