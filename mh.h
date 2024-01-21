#pragma once
#include "minhook.h"
#include <string_view>

namespace MH {
    typedef MH_STATUS STATUS;
    inline constexpr auto ALL_HOOKS = NULL;

    inline STATUS WINAPI Initialize() {
        return MH_Initialize();
    }

    inline STATUS WINAPI Uninitialize() {
        return MH_Uninitialize();
    }

    constexpr inline std::string_view ToString(STATUS _Status) noexcept {
        return MH_StatusToString(_Status);
    }

    template <class _TyAddr, class _TyFunc>
    inline STATUS WINAPI CreateHook(_TyAddr _Target, _TyFunc _Detour, _TyFunc* _Original = nullptr) {
        return MH_CreateHook((LPVOID)_Target, (LPVOID)_Detour, (LPVOID*)_Original);
    }

    template <class _TyFunc>
    inline STATUS WINAPI CreateHookApi(std::string_view _ModuleName, std::string_view _ProcName, _TyFunc _Detour, _TyFunc* _Original = nullptr) {
        HMODULE _Handle = GetModuleHandleA(_ModuleName.data());
        if (_Handle == NULL)
            return MH_ERROR_MODULE_NOT_FOUND;

        LPVOID _Target = GetProcAddress(_Handle, _ProcName.data());
        if (_Target == NULL)
            return MH_ERROR_FUNCTION_NOT_FOUND;

        return CreateHook(_Target, _Detour, _Original);
    }

    template <class _TyFunc>
    inline STATUS WINAPI CreateHookApi(std::wstring_view _ModuleName, std::string_view _ProcName, _TyFunc _Detour, _TyFunc* _Original = nullptr) {
        HMODULE _Handle = GetModuleHandleW(_ModuleName.data());
        if (_Handle == NULL)
            return MH_ERROR_MODULE_NOT_FOUND;

        LPVOID _Target = GetProcAddress(_Handle, _ProcName.data());
        if (_Target == NULL)
            return MH_ERROR_FUNCTION_NOT_FOUND;

        return CreateHook(_Target, _Detour, _Original);
    }

    template <class _TyAddr>
    inline STATUS WINAPI EnableHook(_TyAddr _Target) {
        return MH_EnableHook((LPVOID)_Target);
    }

    inline STATUS WINAPI EnableHookApi(std::string_view _ModuleName, std::string_view _ProcName) {
        HMODULE _Handle = GetModuleHandleA(_ModuleName.data());
        if (_Handle == NULL)
            return MH_ERROR_MODULE_NOT_FOUND;

        LPVOID _Target = GetProcAddress(_Handle, _ProcName.data());
        if (_Target == NULL)
            return MH_ERROR_FUNCTION_NOT_FOUND;

        return EnableHook(_Target);
    }

    inline STATUS WINAPI EnableHookApi(std::wstring_view _ModuleName, std::string_view _ProcName) {
        HMODULE _Handle = GetModuleHandleW(_ModuleName.data());
        if (_Handle == NULL)
            return MH_ERROR_MODULE_NOT_FOUND;

        LPVOID _Target = GetProcAddress(_Handle, _ProcName.data());
        if (_Target == NULL)
            return MH_ERROR_FUNCTION_NOT_FOUND;

        return EnableHook(_Target);
    }

    template <class _TyAddr>
    inline STATUS WINAPI DisableHook(_TyAddr _Target) {
        return MH_DisableHook((LPVOID)_Target);
    }

    inline STATUS WINAPI DisableHookApi(std::string_view _ModuleName, std::string_view _ProcName) {
        HMODULE _Handle = GetModuleHandleA(_ModuleName.data());
        if (_Handle == NULL)
            return MH_ERROR_MODULE_NOT_FOUND;

        LPVOID _Target = GetProcAddress(_Handle, _ProcName.data());
        if (_Target == NULL)
            return MH_ERROR_FUNCTION_NOT_FOUND;

        return DisableHook(_Target);
    }

    inline STATUS WINAPI DisableHookApi(std::wstring_view _ModuleName, std::string_view _ProcName) {
        HMODULE _Handle = GetModuleHandleW(_ModuleName.data());
        if (_Handle == NULL)
            return MH_ERROR_MODULE_NOT_FOUND;

        LPVOID _Target = GetProcAddress(_Handle, _ProcName.data());
        if (_Target == NULL)
            return MH_ERROR_FUNCTION_NOT_FOUND;

        return DisableHook(_Target);
    }

    template <class _TyAddr>
    inline STATUS WINAPI RemoveHook(_TyAddr _Target) {
        return MH_RemoveHook((LPVOID)_Target);
    }

    inline STATUS WINAPI RemoveHookApi(std::string_view _ModuleName, std::string_view _ProcName) {
        HMODULE _Handle = GetModuleHandleA(_ModuleName.data());
        if (_Handle == NULL)
            return MH_ERROR_MODULE_NOT_FOUND;

        LPVOID _Target = GetProcAddress(_Handle, _ProcName.data());
        if (_Target == NULL)
            return MH_ERROR_FUNCTION_NOT_FOUND;

        return RemoveHook(_Target);
    }

    inline STATUS WINAPI RemoveHookApi(std::wstring_view _ModuleName, std::string_view _ProcName) {
        HMODULE _Handle = GetModuleHandleW(_ModuleName.data());
        if (_Handle == NULL)
            return MH_ERROR_MODULE_NOT_FOUND;

        LPVOID _Target = GetProcAddress(_Handle, _ProcName.data());
        if (_Target == NULL)
            return MH_ERROR_FUNCTION_NOT_FOUND;

        return RemoveHook(_Target);
    }

    template <class _TyAddr>
    inline STATUS WINAPI QueueEnableHook(_TyAddr _Target) {
        return MH_QueueEnableHook((LPVOID)_Target);
    }

    inline STATUS WINAPI QueueEnableHookApi(std::string_view _ModuleName, std::string_view _ProcName) {
        HMODULE _Handle = GetModuleHandleA(_ModuleName.data());
        if (_Handle == NULL)
            return MH_ERROR_MODULE_NOT_FOUND;

        LPVOID _Target = GetProcAddress(_Handle, _ProcName.data());
        if (_Target == NULL)
            return MH_ERROR_FUNCTION_NOT_FOUND;

        return QueueEnableHook(_Target);
    }

    inline STATUS WINAPI QueueEnableHookApi(std::wstring_view _ModuleName, std::string_view _ProcName) {
        HMODULE _Handle = GetModuleHandleW(_ModuleName.data());
        if (_Handle == NULL)
            return MH_ERROR_MODULE_NOT_FOUND;

        LPVOID _Target = GetProcAddress(_Handle, _ProcName.data());
        if (_Target == NULL)
            return MH_ERROR_FUNCTION_NOT_FOUND;

        return QueueEnableHook(_Target);
    }

    template <class _TyAddr>
    inline STATUS WINAPI QueueDisableHook(_TyAddr _Target) {
        return MH_QueueDisableHook((LPVOID)_Target);
    }

    inline STATUS WINAPI QueueDisableHookApi(std::string_view _ModuleName, std::string_view _ProcName) {
        HMODULE _Handle = GetModuleHandleA(_ModuleName.data());
        if (_Handle == NULL)
            return MH_ERROR_MODULE_NOT_FOUND;

        LPVOID _Target = GetProcAddress(_Handle, _ProcName.data());
        if (_Target == NULL)
            return MH_ERROR_FUNCTION_NOT_FOUND;

        return QueueDisableHook(_Target);
    }

    inline STATUS WINAPI QueueDisableHookApi(std::wstring_view _ModuleName, std::string_view _ProcName) {
        HMODULE _Handle = GetModuleHandleW(_ModuleName.data());
        if (_Handle == NULL)
            return MH_ERROR_MODULE_NOT_FOUND;

        LPVOID _Target = GetProcAddress(_Handle, _ProcName.data());
        if (_Target == NULL)
            return MH_ERROR_FUNCTION_NOT_FOUND;

        return QueueDisableHook(_Target);
    }

    inline STATUS WINAPI ApplyQueued() {
        return MH_ApplyQueued();
    }

    template <class _TyAddr, class _TyFunc>
    inline STATUS WINAPI InstantHook(_TyAddr _Target, _TyFunc _Detour, _TyFunc* _Original = nullptr) {
        MH_STATUS _Status = CreateHook(_Target, _Detour, _Original);
        if (_Status != MH_OK)
            return _Status;

        return EnableHook(_Target);
    }

    template <class _TyFunc>
    inline STATUS WINAPI InstantHookApi(std::string_view _ModuleName, std::string_view _ProcName, _TyFunc _Detour, _TyFunc* _Original = nullptr) {
        HMODULE _Handle = GetModuleHandleA(_ModuleName.data());
        if (_Handle == NULL)
            return MH_ERROR_MODULE_NOT_FOUND;

        LPVOID _Target = GetProcAddress(_Handle, _ProcName.data());
        if (_Target == NULL)
            return MH_ERROR_FUNCTION_NOT_FOUND;

        return InstantHook(_Target, _Detour, _Original);
    }

    template <class _TyFunc>
    inline STATUS WINAPI InstantHookApi(std::wstring_view _ModuleName, std::string_view _ProcName, _TyFunc _Detour, _TyFunc* _Original = nullptr) {
        HMODULE _Handle = GetModuleHandleW(_ModuleName.data());
        if (_Handle == NULL)
            return MH_ERROR_MODULE_NOT_FOUND;

        LPVOID _Target = GetProcAddress(_Handle, _ProcName.data());
        if (_Target == NULL)
            return MH_ERROR_FUNCTION_NOT_FOUND;

        return InstantHook(_Target, _Detour, _Original);
    }
}
