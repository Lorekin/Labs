function FindSumLengthOfLargeFiles([string]$dir=".", [int]$ratio=2) {
$foldersHash = @{}
$foldersList = [System.Collections.ArrayList]::new()
Get-ChildItem $dir -Recurse | ForEach-Object -Process {
$fileSize = (Get-ChildItem $_.DirectoryName -Recurse | measure-object -property length -average).Count * $ratio
if ($_ -is [System.IO.DirectoryInfo]) {
return
}
if (!$foldersHash.ContainsKey($_.DirectoryName -as [string])) {
$foldersHash[$_.DirectoryName -as [string]] = 0
}
if ($_.Length -ge $fileSize) {
$foldersHash[$_.DirectoryName -as [string]] += $_.Length
}
}
foreach ($d in $foldersHash.GetEnumerator()) {
if ($d.Value -ne 0) {
$foldersList.Add([System.Tuple]::Create($d.Name, $d.Value)) | Out-Null
}
}
foreach ($t in $foldersList) {
Write-Host "${t}"
}
}