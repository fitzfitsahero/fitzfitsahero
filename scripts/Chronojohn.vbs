Option Explicit
Dim wshShell
On Error Resume Next
	Set wshShell = WScript.CreateObject("WSCript.shell")
	If Err.Number <> 0 Then
		WScript.Quit
	End If
	wshSHell.Run "mount -o fileaccess=755 -u:fitz  \\192.168.1.132\shared-write j:"
On Error Goto 0