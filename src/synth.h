#ifndef _SYNTH_H_
#define _SYNTH_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

typedef enum {
    SINE = 0,
    TRIANGLE,
    SAW,
    MEANDER,
    WHITE_NOISE
} synth_waveform_t;

typedef struct synth_t {
    synth_waveform_t waveform;
    uint32_t sample_rate;
    uint32_t frequency; //in herz
    double sample_step; //in radians
    double current_angle; //in radians
} synth_t;

void synth_init(synth_t* synth, synth_waveform_t waveform, uint32_t sample_rate, uint32_t frequency);
double synt_getSample(synth_t* synth);

#ifdef __cplusplus
}
#endif

#endif /* _SYNTH_H_ */