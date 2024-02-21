#pragma once
#include "minhook.h"
#include <string_view>

namespace MH {
    typedef MH_STATUS STATUS;
    inline constexpr auto ALL_HOOKS = MH_ALL_HOOKS;

    STATUS __stdcall Initialize() {
        return MH_Initialize();
    }

    STATUS __stdcall Uninitialize() {
        return MH_Uninitialize();
    }

    const std::string_view __stdcall ToString(STATUS Status) noexcept {
        return MH_StatusToString(Status);
    }

    template <class Ty, class Fn>
    STATUS __stdcall CreateHook(Ty Target, Fn Detour, Fn* Original = nullptr) {
        return MH_CreateHook((void*)Target, (void*)Detour, (void**)Original);
    }

    template <class Fn>
    STATUS __stdcall CreateHookApi(std::string_view ModuleName, std::string_view ProcName, Fn Detour, Fn* Original = nullptr) {
        HMODULE _Handle = GetModuleHandleA(ModuleName.data());
        if (!_Handle)
            return MH_ERROR_MODULE_NOT_FOUND;
        void* _Target = GetProcAddress(_Handle, ProcName.data());
        if (!_Target)
            return MH_ERROR_FUNCTION_NOT_FOUND;
        return CreateHook(_Target, Detour, Original);
    }

    template <class Fn>
    STATUS __stdcall CreateHookApi(std::wstring_view ModuleName, std::string_view ProcName, Fn Detour, Fn* Original = nullptr) {
        HMODULE _Handle = GetModuleHandleW(ModuleName.data());
        if (!_Handle)
            return MH_ERROR_MODULE_NOT_FOUND;
        void* _Target = GetProcAddress(_Handle, ProcName.data());
        if (!_Target)
            return MH_ERROR_FUNCTION_NOT_FOUND;
        return CreateHook(_Target, Detour, Original);
    }

    template <class Ty>
    STATUS __stdcall EnableHook(Ty Target) {
        return MH_EnableHook((void*)Target);
    }

    STATUS __stdcall EnableHookApi(std::string_view ModuleName, std::string_view ProcName) {
        HMODULE _Handle = GetModuleHandleA(ModuleName.data());
        if (!_Handle)
            return MH_ERROR_MODULE_NOT_FOUND;
        void* _Target = GetProcAddress(_Handle, ProcName.data());
        if (!_Target)
            return MH_ERROR_FUNCTION_NOT_FOUND;
        return EnableHook(_Target);
    }

    STATUS __stdcall EnableHookApi(std::wstring_view ModuleName, std::string_view ProcName) {
        HMODULE _Handle = GetModuleHandleW(ModuleName.data());
        if (!_Handle)
            return MH_ERROR_MODULE_NOT_FOUND;
        void* _Target = GetProcAddress(_Handle, ProcName.data());
        if (!_Target)
            return MH_ERROR_FUNCTION_NOT_FOUND;
        return EnableHook(_Target);
    }

    template <class Ty>
    STATUS __stdcall DisableHook(Ty Target) {
        return MH_DisableHook((void*)Target);
    }

    STATUS __stdcall DisableHookApi(std::string_view ModuleName, std::string_view ProcName) {
        HMODULE _Handle = GetModuleHandleA(ModuleName.data());
        if (!_Handle)
            return MH_ERROR_MODULE_NOT_FOUND;
        void* _Target = GetProcAddress(_Handle, ProcName.data());
        if (!_Target)
            return MH_ERROR_FUNCTION_NOT_FOUND;
        return DisableHook(_Target);
    }

    STATUS __stdcall DisableHookApi(std::wstring_view ModuleName, std::string_view ProcName) {
        HMODULE _Handle = GetModuleHandleW(ModuleName.data());
        if (!_Handle)
            return MH_ERROR_MODULE_NOT_FOUND;
        void* _Target = GetProcAddress(_Handle, ProcName.data());
        if (!_Target)
            return MH_ERROR_FUNCTION_NOT_FOUND;
        return DisableHook(_Target);
    }

    template <class Ty>
    STATUS __stdcall RemoveHook(Ty Target) {
        return MH_RemoveHook((void*)Target);
    }

    STATUS __stdcall RemoveHookApi(std::string_view ModuleName, std::string_view ProcName) {
        HMODULE _Handle = GetModuleHandleA(ModuleName.data());
        if (!_Handle)
            return MH_ERROR_MODULE_NOT_FOUND;
        void* _Target = GetProcAddress(_Handle, ProcName.data());
        if (!_Target)
            return MH_ERROR_FUNCTION_NOT_FOUND;
        return RemoveHook(_Target);
    }

    STATUS __stdcall RemoveHookApi(std::wstring_view ModuleName, std::string_view ProcName) {
        HMODULE _Handle = GetModuleHandleW(ModuleName.data());
        if (!_Handle)
            return MH_ERROR_MODULE_NOT_FOUND;
        void* _Target = GetProcAddress(_Handle, ProcName.data());
        if (!_Target)
            return MH_ERROR_FUNCTION_NOT_FOUND;
        return RemoveHook(_Target);
    }

    template <class Ty>
    STATUS __stdcall QueueEnableHook(Ty Target) {
        return MH_QueueEnableHook((void*)Target);
    }

    STATUS __stdcall QueueEnableHookApi(std::string_view ModuleName, std::string_view ProcName) {
        HMODULE _Handle = GetModuleHandleA(ModuleName.data());
        if (!_Handle)
            return MH_ERROR_MODULE_NOT_FOUND;
        void* _Target = GetProcAddress(_Handle, ProcName.data());
        if (!_Target)
            return MH_ERROR_FUNCTION_NOT_FOUND;
        return QueueEnableHook(_Target);
    }

    STATUS __stdcall QueueEnableHookApi(std::wstring_view ModuleName, std::string_view ProcName) {
        HMODULE _Handle = GetModuleHandleW(ModuleName.data());
        if (!_Handle)
            return MH_ERROR_MODULE_NOT_FOUND;
        void* _Target = GetProcAddress(_Handle, ProcName.data());
        if (!_Target)
            return MH_ERROR_FUNCTION_NOT_FOUND;
        return QueueEnableHook(_Target);
    }

    template <class Ty>
    STATUS __stdcall QueueDisableHook(Ty Target) {
        return MH_QueueDisableHook((void*)Target);
    }

    STATUS __stdcall QueueDisableHookApi(std::string_view ModuleName, std::string_view ProcName) {
        HMODULE _Handle = GetModuleHandleA(ModuleName.data());
        if (!_Handle)
            return MH_ERROR_MODULE_NOT_FOUND;
        void* _Target = GetProcAddress(_Handle, ProcName.data());
        if (!_Target)
            return MH_ERROR_FUNCTION_NOT_FOUND;
        return QueueDisableHook(_Target);
    }

    STATUS __stdcall QueueDisableHookApi(std::wstring_view ModuleName, std::string_view ProcName) {
        HMODULE _Handle = GetModuleHandleW(ModuleName.data());
        if (!_Handle)
            return MH_ERROR_MODULE_NOT_FOUND;
        void* _Target = GetProcAddress(_Handle, ProcName.data());
        if (!_Target)
            return MH_ERROR_FUNCTION_NOT_FOUND;
        return QueueDisableHook(_Target);
    }

    STATUS __stdcall ApplyQueued() {
        return MH_ApplyQueued();
    }

    template <class Ty, class Fn>
    STATUS __stdcall InstantHook(Ty Target, Fn Detour, Fn* Original = nullptr) {
        MH_STATUS _Status = CreateHook(Target, Detour, Original);
        if (_Status != MH_OK)
            return _Status;
        return EnableHook(Target);
    }

    template <class Fn>
    STATUS __stdcall InstantHookApi(std::string_view ModuleName, std::string_view ProcName, Fn Detour, Fn* Original = nullptr) {
        HMODULE _Handle = GetModuleHandleA(ModuleName.data());
        if (!_Handle)
            return MH_ERROR_MODULE_NOT_FOUND;
        void* _Target = GetProcAddress(_Handle, ProcName.data());
        if (!_Target)
            return MH_ERROR_FUNCTION_NOT_FOUND;
        return InstantHook(_Target, Detour, Original);
    }

    template <class Fn>
    STATUS __stdcall InstantHookApi(std::wstring_view ModuleName, std::string_view ProcName, Fn Detour, Fn* Original = nullptr) {
        HMODULE _Handle = GetModuleHandleW(ModuleName.data());
        if (!_Handle)
            return MH_ERROR_MODULE_NOT_FOUND;
        void* _Target = GetProcAddress(_Handle, ProcName.data());
        if (!_Target)
            return MH_ERROR_FUNCTION_NOT_FOUND;
        return InstantHook(_Target, Detour, Original);
    }
}
