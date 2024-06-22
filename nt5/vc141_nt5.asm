
.MODEL FLAT

EXTERN _fake_DecodePointer@4 : PROC

EXTERN _fake_EncodePointer@4 : PROC

EXTERN _fake_GetModuleHandleExW@12 : PROC

EXTERN _fake_InitializeSListHead@4 : PROC

.DATA

PUBLIC __imp__DecodePointer@4
__imp__DecodePointer@4 dd _fake_DecodePointer@4

PUBLIC __imp__EncodePointer@4
__imp__EncodePointer@4 dd _fake_EncodePointer@4

PUBLIC __imp__GetModuleHandleExW@12
__imp__GetModuleHandleExW@12 dd _fake_GetModuleHandleExW@12

PUBLIC __imp__InitializeSListHead@4
__imp__InitializeSListHead@4 dd _fake_InitializeSListHead@4

END
