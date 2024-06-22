
$exepath = Resolve-Path $args[0]
$exe = [System.IO.File]::ReadAllBytes($exepath)
$e_lfanew = 0x3c

$pe_start = [System.BitConverter]::ToUInt32($exe, $e_lfanew)
$pe_signature = [System.BitConverter]::ToUInt32($exe, $pe_start)

if ($pe_signature -ne 0x4550) {
    exit 1
}

$exe[$pe_start + 0x40] = 0x05;
$exe[$pe_start + 0x41] = 0x00;

$exe[$pe_start + 0x42] = 0x00;
$exe[$pe_start + 0x43] = 0x00;

$exe[$pe_start + 0x48] = 0x05;
$exe[$pe_start + 0x49] = 0x00;

$exe[$pe_start + 0x4a] = 0x00;
$exe[$pe_start + 0x4b] = 0x00;

[System.IO.File]::WriteAllBytes($exepath, $exe)
