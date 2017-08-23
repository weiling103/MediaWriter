/*
 * Fedora Media Writer
 * Copyright (C) 2016 Martin Bříza <mbriza@redhat.com>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

#ifndef WRITE_H
#define WRITE_H

#include <QString>
#include <QtGlobal>

// Platform specific drive handler.
#include "genericdrive.h"

#ifndef MEDIAWRITER_LZMA_LIMIT
// 256MB memory limit for the decompressor
#define MEDIAWRITER_LZMA_LIMIT (1024 * 1024 * 256)
#endif

struct ProgressStats {
    qint64 progress{ 0LL };
    int syncs{ 0 };
    int fd{ -1 };
};

int onProgress(void *data, long long offset, long long total);
void check(int fd);
void writePlain(const QString &source, GenericDrive *const drive);
void writeCompressed(const QString &source, GenericDrive *const drive);

void write(const QString &source, GenericDrive *const drive, bool persistentStorage = false);

#endif // WRITE_H
