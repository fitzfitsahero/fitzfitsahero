DIM WSHShell
Set WSHShell = WScript.CreateObject("WScript.Shell")
WSHShell.RegWrite "HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\Advanced\EnableBalloonTips", 0,"REG_DWORD"