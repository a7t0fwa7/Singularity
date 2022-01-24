// The legacy support base, this file delcares and imports all legacy type libraries
// and serves as a configuration file for the project.
// Has to be included into every single module file making use of any of the support libraries
#pragma once


// Optional function parameter annotations
#pragma region Singularity annotations
#ifndef IN
#define IN
#endif
#ifndef OUT
#define OUT
#endif
#ifndef INOUT
#define INOUT
#endif
#ifndef OPT
#define OPT
#endif
#pragma endregion


// Disable specific API sets to reduce header size
#pragma region Import and configure windows.h
	#define NOGDICAPMASKS     // CC_*, LC_*, PC_*, CP_*, TC_*, RC_
	#define NOVIRTUALKEYCODES // VK_*
	#define NOWINMESSAGES     // WM_*, EM_*, LB_*, CB_*
	#define NOWINSTYLES       // WS_*, CS_*, ES_*, LBS_*, SBS_*, CBS_*
	#define NOSYSMETRICS      // SM_*
	#define NOMENUS           // MF_*
	#define NOICONS           // IDI_*
	#define NOKEYSTATES       // MK_*
	#define NOSYSCOMMANDS     // SC_*
	#define NORASTEROPS       // Binary and Tertiary raster ops
	#define NOSHOWWINDOW      // SW_*
	#define OEMRESOURCE       // OEM Resource values
	#define NOATOM            // Atom Manager routines
	#define NOCLIPBOARD       // Clipboard routines
	#define NOCOLOR           // Screen colors
	#define NOCTLMGR          // Control and Dialog routines
	#define NODRAWTEXT        // DrawText() and DT_*
	#define NOGDI             // All GDI defines and routines
//	#define NOKERNEL          // All KERNEL defines and routines
	#define NOUSER            // All USER defines and routines
	#define NONLS             // All NLS defines and routines
	#define NOMB              // MB_* and MessageBox()
	#define NOMEMMGR          // GMEM_*, LMEM_*, GHND, LHND, associated routines
	#define NOMETAFILE        // typedef METAFILEPICT
	#define NOMINMAX          // Macros min(a,b) and max(a,b)
	#define NOMSG             // typedef MSG and associated routines
	#define NOOPENFILE        // OpenFile(), OemToAnsi, AnsiToOem, and OF_*
	#define NOSCROLL          // SB_* and scrolling routines
	#define NOSERVICE         // All Service Controller routines, SERVICE_ equates, etc.
	#define NOSOUND           // Sound driver routines
	#define NOTEXTMETRIC      // typedef TEXTMETRIC and associated routines
	#define NOWH              // SetWindowsHook and WH_*
	#define NOWINOFFSETS      // GWL_*, GCL_*, associated routines
	#define NOCOMM            // COMM driver routines
	#define NOKANJI           // Kanji support stuff.
	#define NOHELP            // Help engine interface.
	#define NOPROFILER        // Profiler interface.
	#define NODEFERWINDOWPOS  // DeferWindowPos routines
	#define NOMCX             // Modem Configuration Extensions

// Specific supported windows versions and misc
#define NTDDI_VERSION NTDDI_WIN6SP1
#define _WIN32_WINNT _WIN32_WINNT_VISTA
#define WIN32_LEAN_AND_MEAN
// #define WIN32_NO_STATUS
#include <Windows.h>
// #undef WIN32_NO_STATUS
#pragma endregion
// #include <winternl.h>
// #include <ntstatus.h>


// Configure base includes for shared base and libc
#define _CRT_SECURE_NO_WARNINGS
#include <utility>
#include <memory>
#include <intrin.h>


// Configure and import external legacy libraries
#ifndef NDEBUG
#define SPDLOG_ACTIVE_LEVEL SPDLOG_LEVEL_TRACE
#else
#define SPDLOG_ACTIVE_LEVEL SPDLOG_LEVEL_INFO
#endif
#define SPDLOG_LEVEL_NAMES { "TRACE", "DEBUG", "INFO", "WARNING", "ERROR", "FATAL", "OFF" }
#define SPDLOG_NO_THREAD_ID
#define SPDLOG_NO_ATOMIC_LEVELS
#define SPDLOG_FMT_EXTERNAL
#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>

extern "C" {
#include <xed/xed-interface.h>
}

// Special logging functionalities 
#define TRACE_FUNCTION_PROTO static_cast<void>(0)
#define SPDLOG_SINGULARITY_SMALL_PATTERN "[%^%=7l%$] %v"

// Legacy style type helpers
#define OFFSET_OF offsetof
#define PAGE_SIZE 4096
#define PAGE_ALLOCATION_GRANULARITY 65536

// Project specific types with special meaning
using offset_t = ptrdiff_t; // Type used to store an offset with a maximum capacity of the architectures size
using byte_t = uint8_t;     // Type used to store arbitrary data in the form of a byte with 8 bits
using rva_t = int32_t;      // Type used to describe a 31bit image relative offset, anything negative is invalid
