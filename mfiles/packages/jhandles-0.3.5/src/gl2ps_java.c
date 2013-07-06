#ifdef _MSC_VER
#define _CRT_SECURE_NO_DEPRECATE
#endif

#include <jni.h>
#include <gl2ps.h>
#include <stdio.h>
#include <errno.h>

static FILE* stream = NULL;

#define JSTRING(s) const char* s = (_ ## s ? (*env)->GetStringUTFChars(env, _ ## s, NULL) : NULL)
#define END_JSTRING(s) if (s) (*env)->ReleaseStringUTFChars(env, _ ## s, s)
#define WITH_JSTRING(s, code) \
  JSTRING(s); do { code } while (0); END_JSTRING(s);

#define JINTARRAY(s) jint* s = (_ ## s ? (*env)->GetIntArrayElements(env, _ ## s, NULL) : NULL)
#define END_JINTARRAY(s) if (s) (*env)->ReleaseIntArrayElements(env, _ ## s, s, 0)
#define WITH_JINTARRAY(s, code) \
  JINTARRAY(s); do { code } while (0); END_JINTARRAY(s);

#define JFLOATARRAY(s) jfloat* s = (_ ## s ? (*env)->GetFloatArrayElements(env, _ ## s, NULL) : NULL)
#define END_JFLOATARRAY(s) if (s) (*env)->ReleaseFloatArrayElements(env, _ ## s, s, 0)
#define WITH_JFLOATARRAY(s, code) \
  JFLOATARRAY(s); do { code } while (0); END_JFLOATARRAY(s);

JNIEXPORT jint JNICALL Java_org_octave_graphics_GL2PS_gl2psBeginPage
  (JNIEnv *env, jclass cls,
   jstring _title, jstring _producer,
   jintArray _viewport,
   jint format, jint sort, jint options,
   jint colormode, jint colorsize,
   jobjectArray colortable,
   jint nr, jint ng, jint nb,
   jint buffersize, jstring _outputname,
   jstring _filename)
{
  GLint result;

  WITH_JSTRING(title,
    WITH_JSTRING(producer,
      WITH_JSTRING(outputname,
        WITH_JSTRING(filename,
          WITH_JINTARRAY(viewport,
            if (stream != NULL)
              result = GL2PS_ERROR;
            else
            {
              stream = fopen(outputname, "w");
              if (stream == NULL)
	      {
                printf("cannot open %s for writing\n", outputname);
                result = GL2PS_ERROR;
              }
              else
                result = gl2psBeginPage(
                  title, producer,
                  viewport,
                  format, sort, options,
                  colormode, colorsize,
                  NULL /* TODO */,
                  nr, ng, nb,
                  buffersize, stream,
                  filename);
            }
            )))))

  return result;
}

JNIEXPORT jint JNICALL Java_org_octave_graphics_GL2PS_gl2psEndPage
  (JNIEnv *env, jclass cls)
{
  GLint result = GL2PS_UNINITIALIZED;

  if (stream != NULL)
  {
    result = gl2psEndPage();
    fclose(stream);
    stream = NULL;
  }
  
  return result;
}

JNIEXPORT jint JNICALL Java_org_octave_graphics_GL2PS_gl2psText
  (JNIEnv *env, jclass cls,
   jstring _string, jstring _fontname,
   jint fontsize)
{
  GLint result;

  WITH_JSTRING(string,
    WITH_JSTRING(fontname,
      result = gl2psText(string, fontname, fontsize);
      ))

  return result;
}

JNIEXPORT jint JNICALL Java_org_octave_graphics_GL2PS_gl2psTextOpt
  (JNIEnv *env, jclass cls,
   jstring _string, jstring _fontname,
   jint fontsize, jint align, jfloat angle, jfloat margin,
   jboolean offsetmargin, jfloat linewidth, jfloatArray _linecolor,
   jshort linepattern, jint linefactor, jfloatArray _fillcolor)
{
  GLint result;

  WITH_JSTRING(string,
    WITH_JSTRING(fontname,
      WITH_JFLOATARRAY(linecolor,
        WITH_JFLOATARRAY(fillcolor,
          result = gl2psTextOpt(string, fontname, fontsize, align, angle, margin, offsetmargin,
            linewidth, linecolor, linepattern, linefactor, fillcolor);
          ))))

  return result;
}

JNIEXPORT jint JNICALL Java_org_octave_graphics_GL2PS_gl2psEnable
  (JNIEnv *env, jclass cls, jint mode)
{
  return gl2psEnable(mode);
}

JNIEXPORT jint JNICALL Java_org_octave_graphics_GL2PS_gl2psDisable
  (JNIEnv *env, jclass cls, jint mode)
{
  return gl2psDisable(mode);
}

JNIEXPORT jint JNICALL Java_org_octave_graphics_GL2PS_gl2psBeginViewport
  (JNIEnv *env, jclass cls, jintArray _viewport)
{
  GLint result;

  WITH_JINTARRAY(viewport,
    result = gl2psBeginViewport(viewport);
    )

  return result;
}

JNIEXPORT jint JNICALL Java_org_octave_graphics_GL2PS_gl2psEndViewport
  (JNIEnv *env, jclass cls)
{
  return gl2psEndViewport();
}

JNIEXPORT jint JNICALL Java_org_octave_graphics_GL2PS_gl2psLineWidth
  (JNIEnv *env, jclass cls, jfloat w)
{
  printf("gl2psLineWidth: %f\n", w);
  return gl2psLineWidth(w);
}

JNIEXPORT jint JNICALL Java_org_octave_graphics_GL2PS_gl2psSpecial
  (JNIEnv *env, jclass cls,
   jint format, jstring _string, jint moveTo)
{
  GLint result;

  WITH_JSTRING(string,
    result = gl2psSpecial(format, string, moveTo);
    )

  return result;
}

