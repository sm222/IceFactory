#ifndef  __AUDIO_MANAGER__
# define __AUDIO_MANAGER__

# include "../IImport.hpp"

typedef enum audioTypesEnum {
  e_sound = 0,
  e_music = 1,
} audioTypesEnum;

typedef struct AudioData {
  Sound s;
  Music m;
  audioTypesEnum type;
} AudioData;

# define MAX_SOUND_PLAYING 100
# define MAX_MUSIC_PLAYING 3

typedef std::map<std::string, Sound> MapSound;
typedef std::map<std::string, Music> MapMusic;
typedef std::array<Sound, MAX_SOUND_PLAYING>  PlayingMapSound;
typedef std::array<Music, MAX_MUSIC_PLAYING>  PlayingMapMusic;



class AudioManager : public IImport<AudioData> {
  public:
    //
      AudioManager(void);
      virtual ~AudioManager(void);
    //
    const AudioData  Get(const char* name)                 const;
    bool             IsAllReadyLoad(const char* name)      const;
    bool             IsAllReadyLoadSound(const char* name) const;
    bool             IsAllReadyLoadMusic(const char* name) const;
    // Set
      // Add
        int          Add(const char* name);
        int          AddSound(const char* name);
        int          AddMusic(const char* name);
      // Rm
        int          Remove(const char* name);
        void         Clear(void);
      //
        bool         Play(const char* name);
        bool         Play(const char* name, audioTypesEnum type);
      //
        size_t       Update(void);
  protected:
    
  private:
    MapSound         __sounds;
    MapMusic         __musics;
    //
    PlayingMapSound  __PlayingSounds;
    PlayingMapMusic  __PlayingMusics;
};


#endif
