# Breakout User Manual 


## Getting Started

In 5 simple steps:  
1. Clone/download the repository and open it in Unity 2019.3 or later.  
2. Open the Sample Scene and set the output video resolution by changing the Game View resolution (use 1920x1080 for the xample scene).  
3. Open the Timeline window and select the 'Global Timeline' object.  
4. Enter Playmode to watch the video play. The output is recorded during the 'RecorderClip' within timeline.  
5. Open the 'Recordings' folder which will be created in the project directory and will contain the exported video.  
  

## Tips

1. The project includes a 'Welcome' window to help get you setup. It can also be accessed through the Top Menu Bar.  
2. Use Timeline! It makes everything much easier. Plus the included modifications to fix VideoPlayer bugs are only designed for use with Timeline.  
3. All video clips you use should have 'Transcode' checked in their import settings. This will prevent delays on videos starting to play.  
4. Don't worry about dropping frames. Unity Recorder won't let that happen. So you can export your videos on lower-end devices if you want. The export process will take longer but you won't lose quality.  
5. Use TextMeshPro for all text you use to make sure it is crystal clear. The project includes some popular fonts which are ready to use from [Google Fonts](https://fonts.google.com/).
6. Don't start recording as soon as you enter playmode! In Timeline leave a few seconds before the RecorderClip starts (just like in the sample scene). This is important because some video thrumbnail processing is done in the first second when you enter Playmode.


## References

 

## License

This code is released under MIT license. Modify, distribute, sell, fork, and use this as much as you like. Both for personal and commercial use. We hold no responsibility if anything goes wrong.


## Contributing

Pull Requests are welcome. But, note that by creating a pull request you are giving me permission to merge your code and release it under the MIT license mentioned above. At no point will you be able to withdraw merged code from the repository, or change the license under which it has been made available.


