### Templates

No more casting to void\* or void\*\* every line. That's all done inside of wrappers.

```cpp
MH::CreateHook(some_target, some_detour, &some_original);
```

### Instant hooks

Merge `MH_CreateHook` / `MH_CreateHookApi` and `MH_EnableHook` into one.

```cpp
MH::InstantHook(some_target, some_detour, &some_original);
MH::InstantHook(some_target, some_detour);
MH::InstantHookApi("some_lib.dll", "some_export", some_detour, &some_original);
MH::InstantHookApi(L"some_lib.dll", "some_export", some_detour);
```

### More API functions

You now get access to functions like `MH_EnableHookApi` (which normally isn't a thing).

```cpp
MH::EnableHookApi(L"some_lib.dll", "some_export");
MH::DisableHookApi("some_lib.dll", "some_export");
// ...
```
