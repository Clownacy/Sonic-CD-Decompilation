typedef struct {
  short index;
  unsigned char etc;
  short hoffs;
  short hrevoffs;
  short voffs;
  short vrevoffs;
}
sprite_pattern_mapping_title;

typedef struct {
  short mapnum;
  sprite_pattern_mapping_title aMapDat[2];
}
sprite_pattern_mappings_title;

typedef struct {
  short timer;
  sprite_pattern_mappings_title* paMapTbl;
}
sprite_pattern_title;

typedef struct {
  short patnum;
  sprite_pattern_title aPatDat[10];
}
sprite_patterns_title;
