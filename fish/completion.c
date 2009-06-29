/* libguestfs generated file
 * WARNING: THIS FILE IS GENERATED BY 'src/generator.ml'.
 * ANY CHANGES YOU MAKE TO THIS FILE WILL BE LOST.
 *
 * Copyright (C) 2009 Red Hat Inc.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#include <config.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef HAVE_LIBREADLINE
#include <readline/readline.h>
#endif

#include "fish.h"

#ifdef HAVE_LIBREADLINE

static const char *const commands[] = {
  BUILTIN_COMMANDS_FOR_COMPLETION,
  "launch",
  "run",
  "kill-subprocess",
  "add-drive",
  "add",
  "add-cdrom",
  "cdrom",
  "add-drive-ro",
  "add-ro",
  "config",
  "set-qemu",
  "qemu",
  "get-qemu",
  "set-path",
  "path",
  "get-path",
  "set-append",
  "append",
  "get-append",
  "set-autosync",
  "autosync",
  "get-autosync",
  "set-verbose",
  "verbose",
  "get-verbose",
  "is-ready",
  "is-config",
  "is-launching",
  "is-busy",
  "get-state",
  "mount",
  "sync",
  "touch",
  "cat",
  "ll",
  "ls",
  "list-devices",
  "list-partitions",
  "pvs",
  "vgs",
  "lvs",
  "pvs-full",
  "vgs-full",
  "lvs-full",
  "read-lines",
  "aug-init",
  "aug-close",
  "aug-defvar",
  "aug-defnode",
  "aug-get",
  "aug-set",
  "aug-insert",
  "aug-rm",
  "aug-mv",
  "aug-match",
  "aug-save",
  "aug-load",
  "aug-ls",
  "rm",
  "rmdir",
  "rm-rf",
  "mkdir",
  "mkdir-p",
  "chmod",
  "chown",
  "exists",
  "is-file",
  "is-dir",
  "pvcreate",
  "vgcreate",
  "lvcreate",
  "mkfs",
  "sfdisk",
  "write-file",
  "umount",
  "unmount",
  "mounts",
  "umount-all",
  "unmount-all",
  "lvm-remove-all",
  "file",
  "command",
  "command-lines",
  "stat",
  "lstat",
  "statvfs",
  "tune2fs-l",
  "blockdev-setro",
  "blockdev-setrw",
  "blockdev-getro",
  "blockdev-getss",
  "blockdev-getbsz",
  "blockdev-setbsz",
  "blockdev-getsz",
  "blockdev-getsize64",
  "blockdev-flushbufs",
  "blockdev-rereadpt",
  "upload",
  "download",
  "checksum",
  "tar-in",
  "tar-out",
  "tgz-in",
  "tgz-out",
  "mount-ro",
  "mount-options",
  "mount-vfs",
  "debug",
  "lvremove",
  "vgremove",
  "pvremove",
  "set-e2label",
  "get-e2label",
  "set-e2uuid",
  "get-e2uuid",
  "fsck",
  "zero",
  "grub-install",
  "cp",
  "cp-a",
  "mv",
  "drop-caches",
  "dmesg",
  "ping-daemon",
  "equal",
  "strings",
  "strings-e",
  "hexdump",
  "zerofree",
  "pvresize",
  "sfdisk-N",
  "sfdisk-l",
  "sfdisk-kernel-geometry",
  "sfdisk-disk-geometry",
  "vg-activate-all",
  "vg-activate",
  "lvresize",
  "resize2fs",
  "find",
  "e2fsck-f",
  "sleep",
  "ntfs-3g-probe",
  "sh",
  "sh-lines",
  "glob-expand",
  "scrub-device",
  "scrub-file",
  "scrub-freespace",
  "mkdtemp",
  "wc-l",
  "wc-w",
  "wc-c",
  "head",
  "head-n",
  "tail",
  "tail-n",
  "df",
  "df-h",
  NULL
};

static char *
generator (const char *text, int state)
{
  static int index, len;
  const char *name;

  if (!state) {
    index = 0;
    len = strlen (text);
  }

  rl_attempted_completion_over = 1;

  while ((name = commands[index]) != NULL) {
    index++;
    if (strncasecmp (name, text, len) == 0)
      return strdup (name);
  }

  return NULL;
}

#endif /* HAVE_LIBREADLINE */

char **do_completion (const char *text, int start, int end)
{
  char **matches = NULL;

#ifdef HAVE_LIBREADLINE
  rl_completion_append_character = ' ';

  if (start == 0)
    matches = rl_completion_matches (text, generator);
  else if (complete_dest_paths)
    matches = rl_completion_matches (text, complete_dest_paths_generator);
#endif

  return matches;
}
