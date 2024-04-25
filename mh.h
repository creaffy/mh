#pragma once
#include "minhook.h"
#include <string>

namespace mh {
    using status_t = MH_STATUS;
    constexpr inline void* all_hooks = nullptr;

    inline status_t init() {
        return MH_Initialize();
    }

    inline status_t uninit() {
        return MH_Uninitialize();
    }

    inline std::string_view to_string(status_t Status) noexcept {
        return MH_StatusToString(Status);
    }

    template <class T, class Fn>
    inline status_t create_hook(T Target, Fn Detour, Fn* Original = nullptr) {
        return MH_CreateHook(reinterpret_cast<void*>(Target), reinterpret_cast<void*>(Detour), reinterpret_cast<void**>(Original));
    }

    template <class Fn>
    inline status_t create_hook_api(std::string_view Module, std::string_view Export, Fn Detour, Fn* Original = nullptr) {
        HMODULE handle = GetModuleHandleA(Module.data());
        if (!handle)
            return MH_ERROR_MODULE_NOT_FOUND;

        void* target = GetProcAddress(handle, Export.data());
        if (!target)
            return MH_ERROR_FUNCTION_NOT_FOUND;

        return CreateHook(target, Detour, Original);
    }

    template <class Fn>
    inline status_t create_hook_api(std::wstring_view Module, std::string_view Export, Fn Detour, Fn* Original = nullptr) {
        HMODULE handle = GetModuleHandleW(Module.data());
        if (!handle)
            return MH_ERROR_MODULE_NOT_FOUND;

        void* target = GetProcAddress(handle, Export.data());
        if (!target)
            return MH_ERROR_FUNCTION_NOT_FOUND;

        return CreateHook(target, Detour, Original);
    }

    template <class T>
    inline status_t enable_hook(T Target) {
        return MH_EnableHook(reinterpret_cast<void*>(Target));
    }

    inline status_t enable_hook_api(std::string_view Module, std::string_view Export) {
        HMODULE handle = GetModuleHandleA(Module.data());
        if (!handle)
            return MH_ERROR_MODULE_NOT_FOUND;

        void* target = GetProcAddress(handle, Export.data());
        if (!target)
            return MH_ERROR_FUNCTION_NOT_FOUND;

        return enable_hook(target);
    }

    inline status_t enable_hook_api(std::wstring_view Module, std::string_view Export) {
        HMODULE handle = GetModuleHandleW(Module.data());
        if (!handle)
            return MH_ERROR_MODULE_NOT_FOUND;

        void* target = GetProcAddress(handle, Export.data());
        if (!target)
            return MH_ERROR_FUNCTION_NOT_FOUND;

        return enable_hook(target);
    }

    template <class T>
    inline status_t disable_hook(T Target) {
        return MH_DisableHook(reinterpret_cast<void*>(Target));
    }

    inline status_t disable_hook_api(std::string_view Module, std::string_view Export) {
        HMODULE handle = GetModuleHandleA(Module.data());
        if (!handle)
            return MH_ERROR_MODULE_NOT_FOUND;

        void* target = GetProcAddress(handle, Export.data());
        if (!target)
            return MH_ERROR_FUNCTION_NOT_FOUND;

        return disable_hook(target);
    }

    inline status_t disable_hook_api(std::wstring_view Module, std::string_view Export) {
        HMODULE handle = GetModuleHandleW(Module.data());
        if (!handle)
            return MH_ERROR_MODULE_NOT_FOUND;

        void* target = GetProcAddress(handle, Export.data());
        if (!target)
            return MH_ERROR_FUNCTION_NOT_FOUND;

        return disable_hook(target);
    }

    template <class T>
    inline status_t remove_hook(T Target) {
        return MH_RemoveHook(reinterpret_cast<void*>(Target));
    }

    inline status_t remove_hook_api(std::string_view Module, std::string_view Export) {
        HMODULE handle = GetModuleHandleA(Module.data());
        if (!handle)
            return MH_ERROR_MODULE_NOT_FOUND;

        void* target = GetProcAddress(handle, Export.data());
        if (!target)
            return MH_ERROR_FUNCTION_NOT_FOUND;

        return remove_hook(target);
    }

    inline status_t remove_hook_api(std::wstring_view Module, std::string_view Export) {
        HMODULE handle = GetModuleHandleW(Module.data());
        if (!handle)
            return MH_ERROR_MODULE_NOT_FOUND;

        void* target = GetProcAddress(handle, Export.data());
        if (!target)
            return MH_ERROR_FUNCTION_NOT_FOUND;

        return remove_hook(target);
    }

    template <class T>
    inline status_t queue_enable_hook(T Target) {
        return MH_QueueEnableHook(reinterpret_cast<void*>(Target));
    }

    inline status_t queue_enable_hook_api(std::string_view Module, std::string_view Export) {
        HMODULE handle = GetModuleHandleA(Module.data());
        if (!handle)
            return MH_ERROR_MODULE_NOT_FOUND;

        void* target = GetProcAddress(handle, Export.data());
        if (!target)
            return MH_ERROR_FUNCTION_NOT_FOUND;

        return queue_enable_hook(target);
    }

    inline status_t queue_enable_hook_api(std::wstring_view Module, std::string_view Export) {
        HMODULE handle = GetModuleHandleW(Module.data());
        if (!handle)
            return MH_ERROR_MODULE_NOT_FOUND;

        void* target = GetProcAddress(handle, Export.data());
        if (!target)
            return MH_ERROR_FUNCTION_NOT_FOUND;

        return queue_enable_hook(target);
    }

    template <class T>
    inline status_t queue_disable_hook(T Target) {
        return MH_QueueDisableHook(reinterpret_cast<void*>(Target));
    }

    inline status_t queue_disable_hook_api(std::string_view Module, std::string_view Export) {
        HMODULE handle = GetModuleHandleA(Module.data());
        if (!handle)
            return MH_ERROR_MODULE_NOT_FOUND;

        void* target = GetProcAddress(handle, Export.data());
        if (!target)
            return MH_ERROR_FUNCTION_NOT_FOUND;

        return queue_disable_hook(target);
    }

    inline status_t queue_disable_hook_api(std::wstring_view Module, std::string_view Export) {
        HMODULE handle = GetModuleHandleW(Module.data());
        if (!handle)
            return MH_ERROR_MODULE_NOT_FOUND;

        void* target = GetProcAddress(handle, Export.data());
        if (!target)
            return MH_ERROR_FUNCTION_NOT_FOUND;

        return queue_disable_hook(target);
    }

    inline status_t apply_queued() {
        return MH_ApplyQueued();
    }

    template <class T, class Fn>
    inline status_t instant_hook(T Target, Fn Detour, Fn* Original = nullptr) {
        status_t status = create_hook(Target, Detour, Original);
        if (status != MH_OK)
            return status;

        return enable_hook(Target);
    }

    template <class Fn>
    inline status_t instant_hook_api(std::string_view Module, std::string_view Export, Fn Detour, Fn* Original = nullptr) {
        HMODULE handle = GetModuleHandleA(Module.data());
        if (!handle)
            return MH_ERROR_MODULE_NOT_FOUND;

        void* target = GetProcAddress(handle, Export.data());
        if (!target)
            return MH_ERROR_FUNCTION_NOT_FOUND;

        return instant_hook(target, Detour, Original);
    }

    template <class Fn>
    inline status_t InstantHookApi(std::wstring_view Module, std::string_view Export, Fn Detour, Fn* Original = nullptr) {
        HMODULE handle = GetModuleHandleW(Module.data());
        if (!handle)
            return MH_ERROR_MODULE_NOT_FOUND;

        void* target = GetProcAddress(handle, Export.data());
        if (!target)
            return MH_ERROR_FUNCTION_NOT_FOUND;

        return instant_hook(target, Detour, Original);
    }
}
