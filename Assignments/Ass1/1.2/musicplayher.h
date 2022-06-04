#ifndef __MUSICPLAYER__
#define __MUSICPLAYER__


struct musicplayher
{
  
   State Current;
    Queue Playlist;
    

};


struct State
{
    bool Playing; // worked on by PlayPause
    double   Volume ;//worked on by ChangeVolume
    bool Looping;
 
    double PlaybackSpeed;
    /* data */
    musicFile A;
};



struct musicFile
{
    /* data */ //This is a Music File
    double length;//length in seconds
};


void ChangeVolume(musicplayher Player); // This funciton changes volume
void ChangePlaybackSpeed(musicplayher Player,double Speed); // This funciton changes volume
void Queue(musicFile A,musicplayher Player);// Adds a song to end of queue
void Dequeue(musicFile A,musicplayher Player);//removes song from queue
void playPause(musicplayher Player); // Changes STATE of musicplayer to playing the song or pausing playback
void SwitchLoopState(musicplayher Player);//enables/disables looping
void seek(musicplayher Player, double Time );///Seeks to given time
void changeTrack(musicplayher Player, int QueueNo.);//Changes Track
void stop(musicplayher Player);// stops playback and kills program

void SongSearch(musicplayher Player,char *Name);// searches for a song name

void InputStyle(musicplayher Player, char *Name);//bluetooth, usb etc



#endif