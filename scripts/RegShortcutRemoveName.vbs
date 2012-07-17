DIM WSHShell
Set WSHShell = WScript.CreateObject("WScript.Shell")
WSHShell.RegWrite "HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\link", 00 00 00 00,"REG_BINARY"