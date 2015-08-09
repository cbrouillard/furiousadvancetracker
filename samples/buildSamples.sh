nbKit=$(expr `ls -l | wc -l` - 3)
echo "$nbKit" > 0nbkit
find . -name "*.wav" -exec ffmpeg -y -i {} -ac 1 -ar 16000 -f s8 -acodec pcm_s8 {}.snd \;
find . -name "*.mp3" -exec ffmpeg -y -i {} -ac 1 -ar 16000 -f s8 -acodec pcm_s8 {}.snd \;
