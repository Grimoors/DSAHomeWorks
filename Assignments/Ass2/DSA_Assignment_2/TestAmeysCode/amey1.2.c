#ifndef _musicplayer_h_
#define _musicplayer_h_

typedef struct musicplayer songname;
typedef struct nowplaying ui;


struct musicplayer  {
    int max_song_name_len;
    // "Endgame by Taylor Swift ft Ed Sheeran,Future" is 45 characters long
    
    int index;
    // lets say we have 150 songs,each of whom have namelength <50
    
    char playlist [i][];
   // where i is an element of indices of songs of playlist
  
    char song_list [index][max_song_name_len];
    // song_list [100][] would be the 100th song
};

struct nowplaying {
    double song_duration; 
 //length of the entire song
    
    double time_of_a_song_played;
 //how much time of the duration has been currently played, seconds++ 

};

void playpause(const nowplaying time_of_a_song_played);
// stop/resume incrementing time_of_a_song_played

void forwardsbackwards(const nowplaying time_of_a_song_played);
// incrementing/decrementing time_of_a_song_played by 10 seconds 

void previousnext(const nowplaying time_of_a_song_played);
// set time_of_a_song_played to 0, index by ++/--

#endif