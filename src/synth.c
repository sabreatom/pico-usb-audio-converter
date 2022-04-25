#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "synth.h"

#define PI                          3.14159265

void synth_init(synth_t* synth, synth_waveform_t waveform, uint32_t sample_rate, uint32_t frequency)
{
    synth->waveform = waveform;
    synth->sample_rate = sample_rate;
    synth->frequency = frequency;

    synth->current_angle = 0.0;
    synth->sample_step = 2.0 * PI * frequency / sample_rate;
}

double synt_getSample(synth_t* synth)
{
    double ret = sin(synth->current_angle);
    synth->current_angle += synth->sample_step;

    return ret;
}