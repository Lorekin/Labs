function CopyFilesWithMask([string]$source=".", [string]$dest=".", [string]$mask="") {
Get-ChildItem $source -Recurse | ForEach-Object -Process {
if (Test-Path ($_.FullName -Replace [Regex]::Escape($source), $dest)) {
return
}
if ($mask -ne "") {
if (!($_.BaseName -match $mask)) {
return
}
}
$path = ($_.DirectoryName + "\") -Replace [Regex]::Escape($source), $dest
if (!(Test-Path $path)) {
New-Item -ItemType Directory -Path $path -Force | Out-Null
}
Copy-Item $_.FullName -Destination $path -Force
}
}