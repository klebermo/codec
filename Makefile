export base_dir := ${CURDIR}
export obj_dir := ${base_dir}/build
export release_dir := ${base_dir}/release

export lib_obj_src := ${base_dir}/OBJ
export lib_mtl_src := ${base_dir}/MTL

export lib_avi_src := ${base_dir}/AVI
export lib_h264_src := ${base_dir}/H.264
export lib_h265_src := ${base_dir}/H.265
export lib_h266_src := ${base_dir}/H.266

export lib_jpeg_src := ${base_dir}/JPEG
export lib_png_src := ${base_dir}/PNG
export lib_pbm_src := ${base_dir}/Netpbm

export lib_midi_src := ${base_dir}/MIDI
export lib_wav_src := ${base_dir}/WAV

lib_obj := ${lib_obj_src}
lib_mtl := ${lib_mtl_src}

lib_avi := ${lib_avi_src}
lib_h264 := ${lib_h264_src}
lib_h265 := ${lib_h265_src}
lib_h266 := ${lib_h266_src}

lib_jpeg := ${lib_jpeg_src}
lib_png := ${lib_png_src}
lib_pbm := ${lib_pbm_src}

lib_midi := ${lib_midi_src}
lib_wav := ${lib_wav_src}

libraries := $(lib_obj) $(lib_mtl) $(lib_avi) $(lib_h264) $(lib_h265) $(lib_h266) $(lib_jpeg) $(lib_png) $(lib_pbm) $(lib_midi) $(lib_wav)

.PHONY: all $(libraries)
all: $(libraries)

$(libraries): | ${obj_dir} ${release_dir}
	$(MAKE) --directory=$@

clean:
	rm build/*.o
	rm release/*.a
	rm release/*.so
