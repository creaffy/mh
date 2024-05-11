#pragma once
#include "minhook.h"
#include <string>

namespace MH {
    using STATUS = MH_STATUS;
    constexpr inline void* ALL_HOOKS = nullptr;

    inline STATUS Initialize() {
        return MH_Initialize();
    }

    inline STATUS Uninitialize() {
        return MH_Uninitialize();
    }

    inline std::string_view ToString(STATUS Status) noexcept {
        return MH_StatusToString(Status);
    }

    template <class T, class Fn>
    inline STATUS CreateHook(T Target, Fn Detour, Fn* Original = nullptr) {
        return MH_CreateHook(reinterpret_cast<void*>(Target), reinterpret_cast<void*>(Detour), reinterpret_cast<void**>(Original));
    }

    template <class Fn>
    inline STATUS CreateHookApi(std::string_view Module, std::string_view Export, Fn Detour, Fn* Original = nullptr) {
        HMODULE handle = GetModuleHandleA(Module.data());
        if (!handle)
            return MH_ERROR_MODULE_NOT_FOUND;

        void* target = GetProcAddress(handle, Export.data());
        if (!target)
            return MH_ERROR_FUNCTION_NOT_FOUND;

        return CreateHook(target, Detour, Original);
    }

    template <class Fn>
    inline STATUS CreateHookApi(std::wstring_view Module, std::string_view Export, Fn Detour, Fn* Original = nullptr) {
        HMODULE handle = GetModuleHandleW(Module.data());
        if (!handle)
            return MH_ERROR_MODULE_NOT_FOUND;

        void* target = GetProcAddress(handle, Export.data());
        if (!target)
            return MH_ERROR_FUNCTION_NOT_FOUND;

        return CreateHook(target, Detour, Original);
    }

    template <class T>
    inline STATUS EnableHook(T Target) {
        return MH_EnableHook(reinterpret_cast<void*>(Target));
    }

    inline STATUS EnableHookApi(std::string_view Module, std::string_view Export) {
        HMODULE handle = GetModuleHandleA(Module.data());
        if (!handle)
            return MH_ERROR_MODULE_NOT_FOUND;

        void* target = GetProcAddress(handle, Export.data());
        if (!target)
            return MH_ERROR_FUNCTION_NOT_FOUND;

        return EnableHook(target);
    }

    inline STATUS EnableHookApi(std::wstring_view Module, std::string_view Export) {
        HMODULE handle = GetModuleHandleW(Module.data());
        if (!handle)
            return MH_ERROR_MODULE_NOT_FOUND;

        void* target = GetProcAddress(handle, Export.data());
        if (!target)
            return MH_ERROR_FUNCTION_NOT_FOUND;

        return EnableHook(target);
    }

    template <class T>
    inline STATUS DisableHook(T Target) {
        return MH_DisableHook(reinterpret_cast<void*>(Target));
    }

    inline STATUS DisableHookApi(std::string_view Module, std::string_view Export) {
        HMODULE handle = GetModuleHandleA(Module.data());
        if (!handle)
            return MH_ERROR_MODULE_NOT_FOUND;

        void* target = GetProcAddress(handle, Export.data());
        if (!target)
            return MH_ERROR_FUNCTION_NOT_FOUND;

        return DisableHook(target);
    }

    inline STATUS DisableHookApi(std::wstring_view Module, std::string_view Export) {
        HMODULE handle = GetModuleHandleW(Module.data());
        if (!handle)
            return MH_ERROR_MODULE_NOT_FOUND;

        void* target = GetProcAddress(handle, Export.data());
        if (!target)
            return MH_ERROR_FUNCTION_NOT_FOUND;

        return DisableHook(target);
    }

    template <class T>
    inline STATUS RemoveHook(T Target) {
        return MH_RemoveHook(reinterpret_cast<void*>(Target));
    }

    inline STATUS RemoveHookApi(std::string_view Module, std::string_view Export) {
        HMODULE handle = GetModuleHandleA(Module.data());
        if (!handle)
            return MH_ERROR_MODULE_NOT_FOUND;

        void* target = GetProcAddress(handle, Export.data());
        if (!target)
            return MH_ERROR_FUNCTION_NOT_FOUND;

        return RemoveHook(target);
    }

    inline STATUS RemoveHookApi(std::wstring_view Module, std::string_view Export) {
        HMODULE handle = GetModuleHandleW(Module.data());
        if (!handle)
            return MH_ERROR_MODULE_NOT_FOUND;

        void* target = GetProcAddress(handle, Export.data());
        if (!target)
            return MH_ERROR_FUNCTION_NOT_FOUND;

        return RemoveHook(target);
    }

    template <class T>
    inline STATUS QueueEnableHook(T Target) {
        return MH_QueueEnableHook(reinterpret_cast<void*>(Target));
    }

    inline STATUS QueueEnableHookApi(std::string_view Module, std::string_view Export) {
        HMODULE handle = GetModuleHandleA(Module.data());
        if (!handle)
            return MH_ERROR_MODULE_NOT_FOUND;

        void* target = GetProcAddress(handle, Export.data());
        if (!target)
            return MH_ERROR_FUNCTION_NOT_FOUND;

        return QueueEnableHook(target);
    }

    inline STATUS QueueEnableHookApi(std::wstring_view Module, std::string_view Export) {
        HMODULE handle = GetModuleHandleW(Module.data());
        if (!handle)
            return MH_ERROR_MODULE_NOT_FOUND;

        void* target = GetProcAddress(handle, Export.data());
        if (!target)
            return MH_ERROR_FUNCTION_NOT_FOUND;

        return QueueEnableHook(target);
    }

    template <class T>
    inline STATUS QueueDisableHook(T Target) {
        return MH_QueueDisableHook(reinterpret_cast<void*>(Target));
    }

    inline STATUS QueueDisableHookApi(std::string_view Module, std::string_view Export) {
        HMODULE handle = GetModuleHandleA(Module.data());
        if (!handle)
            return MH_ERROR_MODULE_NOT_FOUND;

        void* target = GetProcAddress(handle, Export.data());
        if (!target)
            return MH_ERROR_FUNCTION_NOT_FOUND;

        return QueueDisableHook(target);
    }

    inline STATUS QueueDisableHookApi(std::wstring_view Module, std::string_view Export) {
        HMODULE handle = GetModuleHandleW(Module.data());
        if (!handle)
            return MH_ERROR_MODULE_NOT_FOUND;

        void* target = GetProcAddress(handle, Export.data());
        if (!target)
            return MH_ERROR_FUNCTION_NOT_FOUND;

        return QueueDisableHook(target);
    }

    inline STATUS ApplyQueued() {
        return MH_ApplyQueued();
    }

    template <class T, class Fn>
    inline STATUS InstantHook(T Target, Fn Detour, Fn* Original = nullptr) {
        STATUS status = CreateHook(Target, Detour, Original);
        if (status != MH_OK)
            return status;

        return EnableHook(Target);
    }

    template <class Fn>
    inline STATUS InstantHookApi(std::string_view Module, std::string_view Export, Fn Detour, Fn* Original = nullptr) {
        HMODULE handle = GetModuleHandleA(Module.data());
        if (!handle)
            return MH_ERROR_MODULE_NOT_FOUND;

        void* target = GetProcAddress(handle, Export.data());
        if (!target)
            return MH_ERROR_FUNCTION_NOT_FOUND;

        return InstantHook(target, Detour, Original);
    }

    template <class Fn>
    inline STATUS InstantHookApi(std::wstring_view Module, std::string_view Export, Fn Detour, Fn* Original = nullptr) {
        HMODULE handle = GetModuleHandleW(Module.data());
        if (!handle)
            return MH_ERROR_MODULE_NOT_FOUND;

        void* target = GetProcAddress(handle, Export.data());
        if (!target)
            return MH_ERROR_FUNCTION_NOT_FOUND;

        return InstantHook(target, Detour, Original);
    }
}