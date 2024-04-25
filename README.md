### Templates

No more casting to void\* or void\*\* every line. That's all done inside of wrappers.

```cpp
void hook() {};
void(*original){};
std::uintptr_t some_ptr{ 0x12345678 };

mh::status_t status = mh::create_hook(some_ptr, hook, &original);
```

### Instant hooks

Merge `MH_CreateHook` / `MH_CreateHookApi` and `MH_EnableHook` into one.

```cpp
mh::instant_hook(some_ptr, some_hook, &some_original);
mh::instant_hook(some_ptr, some_hook);
mh::instant_hook_api("some_lib.dll", "some_export.dll", some_hook, &some_original);
mh::instant_hook_api(L"some_lib.dll", "some_export.dll", some_hook);
```

### More API functions

You now get access to functions like `MH_EnableHookApi` (which normally isn't a thing).

```cpp
mh::enable_hook_api(L"some_lib.dll", "some_export.dll");
mh::disable_hook_api("some_lib.dll", "some_export.dll");
// ...
```
