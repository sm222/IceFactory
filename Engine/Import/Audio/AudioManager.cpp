#include "AudioManager.hpp"


AudioManager::AudioManager(void): IImport<AudioData>() {
  DEBUG_P(magenta, "AudioManager");
  InitAudioDevice();
  if (!IsAudioDeviceReady())
    throw std::runtime_error("audio device faild");
  SetMasterVolume(0.2);
  for (size_t i = 0; i < MAX_SOUND_PLAYING; i++) {
    memset(&__PlayingSounds[i], 0, sizeof(Sound));
  }
}

AudioManager::~AudioManager(void) {
  DEBUG_P(magenta, "AudioManager...");
  if (!IsAudioDeviceReady()) {
    Clear();
    CloseAudioDevice();
  }
}

int  AudioManager::Add(const char* name) {
  DEBUG_P(red, "use AddSound or AddMusic...");
  DEBUG_P(red, "fail to add %s", !name ? "noname" : name);
  return 1;
}

int  AudioManager::AddSound(const char* name) {
  if(!name) {
    DEBUG_P(red, "fail to add audio missing name");
    return 1;
  }
  if (IsAllReadyLoadSound(name)) {
    DEBUG_P(red, "AddSound: %s is all ready load in", name);
    return 2;
  }
  Sound s = LoadSound(name);
  if (IsSoundValid(s)) {
    __sounds[std::string(name)] = s;
    DEBUG_P(cyan, "add %s to sounds", name);
    return 0;
  }
  return 1;
}

int  AudioManager::AddMusic(const char* name) {
  if(!name) {
    DEBUG_P(red, "fail to add audio missing name");
    return 1;
  }
  return 0;
}


int  AudioManager::Remove(const char* name) {
  (void)name;
  return 0;
}

void  AudioManager::Clear(void) {
  for (MapSound::iterator it = __sounds.begin(); it != __sounds.end(); it++) {
    if (IsSoundValid(it->second))
      UnloadSound(it->second);
  }
  __sounds.clear();
  for (PlayingMapSound::iterator it = __PlayingSounds.begin(); it != __PlayingSounds.end(); it++) {
    if (!IsSoundValid(*it)) {
      UnloadSoundAlias(*it);
    }
    memset(&(*it), 0, sizeof((*it)));
  }
}

const AudioData AudioManager::Get(const char* name) const {
  (void)name;
  AudioData a;
  memset(&a, 0, sizeof(a));
  return a;
}

bool   AudioManager::Play(const char* name) {
  MapSound::iterator it = __sounds.find(name);
  if (it != __sounds.end()) {
    size_t i = 0;
    while (i < MAX_SOUND_PLAYING) {
      if (IsSoundValid(__PlayingSounds[i]))
        i++;
      else
        break;
    }
    if (i < MAX_SOUND_PLAYING) {
      DEBUG_P(green, "AudioManager::Play %s [%u]", name, i);
      __PlayingSounds[i] = LoadSoundAlias(it->second);
      PlaySound(__PlayingSounds[i]);
      return 0;
    }
  }
  return 1;
}


bool    AudioManager::IsAllReadyLoad(const char* name) const {
  (void)name;
  DEBUG_P(red, "IsAllReadyLoad call" \
    "IsAllReadyLoadSound IsAllReadyLoadMusic");
  return false;
}

bool  AudioManager::IsAllReadyLoadSound(const char* name) const {
  if (!name) {
    DEBUG_P(red, "IsAllReadyLoadSound missing name");
    return false;
  }
  MapSound::const_iterator it = __sounds.find(name);
  return it != __sounds.end() ? true : false;
}

bool  AudioManager::IsAllReadyLoadMusic(const char* name) const {
  if (!name) {
    DEBUG_P(red, "IsAllReadyLoadMusic missing name");
    return false;
  }
  MapMusic::const_iterator it = __musics.find(name);
  return it != __musics.end() ? true : false;
}



size_t  AudioManager::Update(void) {
  PlayingMapSound::iterator it = __PlayingSounds.begin();
  for (; it != __PlayingSounds.end(); it++) {
    if (IsSoundValid(*it) && !IsSoundPlaying(*it)) {
      UnloadSoundAlias(*it);
      memset(&(*it), 0, sizeof(*it));
      it--;
    }
  }
  return __PlayingSounds.size();
}