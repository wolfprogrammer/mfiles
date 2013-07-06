/* Copyright (C) 2007 Michael Goffioul
**
** This program is free software; you can redistribute it and/or modify
** it under the terms of the GNU General Public License as published by
** the Free Software Foundation; either version 2 of the License, or
** (at your option) any later version.
**
** This program is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU General Public License for more details.
**
** You should have received a copy of the GNU General Public License
** along with this program; if not, <http://www.gnu.org/licenses/>.
*/

#include <octave/oct.h>
#include <octave/graphics.h>
#include <octave/unwind-prot.h>
#include <__java__.h>

#define TO_JAVA(obj) dynamic_cast<octave_java*>((obj).internal_rep())

// Utility functions

static octave_value handle_to_object (const octave_value& h)
{
  return octave_java::do_java_invoke("org.octave.graphics.HandleObject", "getHandleObject", h);
}

static octave_value get_parent_arg (octave_value_list& args, int idx)
{
  octave_value retval;
  caseless_str pstr ("parent");

  for (int i = idx; i < args.length (); i += 2)
    {
      if (args(i).is_string () && (i+1) < args.length ())
        {
          if (pstr.compare (args(i).string_value ()))
            {
              retval = args(i+1);
              args = args.splice (i, 2);
            }
        }
      else
        return retval;
    }

  return retval;
}

static void set_properties (octave_java *obj, const octave_value_list& args, octave_idx_type idx)
{
  octave_value_list set_args(2, octave_value ());

  unwind_protect::begin_frame ("jhandles_set_properties");
  unwind_protect_bool (Vjava_convert_matrix);
  unwind_protect_bool (Vjava_unsigned_conversion);

  Vjava_convert_matrix = true;
  Vjava_unsigned_conversion = true;

  for (int i = idx; (! error_state) && (i < (args.length () - 1)); i += 2)
    {
      set_args(0) = args(i);
      set_args(1) = args(i+1);
      obj->do_java_invoke ("set", set_args);
    }

  unwind_protect::run_frame ("jhandles_set_properties");
}

static void initialize_object (octave_java *obj, const octave_value_list& args, octave_idx_type idx)
{
  if (args.length () > idx)
    set_properties (obj, args, idx);

  if (! error_state)
    obj->do_java_invoke ("validate", octave_value_list ());
}

// Octave interface functions

DEFUN_DLD (__jhandles__, args, , "")
{
  return octave_value ();
}

DEFUN_DLD (__jhandles_go_patch2, _args, , "")
{
  octave_value_list args (_args);
  octave_value parent = get_parent_arg (args, 1);
  octave_value retval;

  if (parent.is_undefined ())
    parent = args(0);

  parent = handle_to_object (parent);
  if (error_state)
    return retval;

  octave_value obj = octave_java::do_java_create ("org.octave.graphics.PatchObject", parent);

  if (! error_state)
    {
      octave_java *jobj = TO_JAVA (obj);
      octave_value handle = jobj->do_java_invoke ("getHandle", octave_value_list ());

      initialize_object (jobj, args, 1);
      if (! error_state)
        retval = handle;
    }

  return retval;
}
