# signpost
Defold engine native extension, that helps to mark points of interest in Xcode Instruments.



https://user-images.githubusercontent.com/2209596/171910263-78ffab24-1be8-4537-a7f9-7725971c39c1.mp4



## API

```Lua
signpost.event("string_info")
```
<img width="659" alt="image" src="https://user-images.githubusercontent.com/2209596/171815074-cc5c4def-b565-40a5-8f1b-ce0a387b73ab.png">



```Lua
	local id = signpost.start("string_start_info")
	-- your code
	signpost.stop(id, "string_stop_info")
```
<img width="681" alt="image" src="https://user-images.githubusercontent.com/2209596/171813998-cf59bef7-ee40-4438-9ec4-be10d5fead6f.png">

If you have any issues, questions or suggestions please [create an issue](https://github.com/AGulev/extension-signpost/issues) or contact me: me@agulev.com
