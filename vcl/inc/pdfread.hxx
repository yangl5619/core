/* -*- Mode: C++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */
/*
 * This file is part of the LibreOffice project.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#ifndef INCLUDED_VCL_SOURCE_FILTER_IPDF_PDFREAD_HXX
#define INCLUDED_VCL_SOURCE_FILTER_IPDF_PDFREAD_HXX

#include <tools/stream.hxx>
#include <com/sun/star/uno/Sequence.hxx>

class Bitmap;
class Graphic;

namespace vcl
{

/// Imports a PDF stream into rGraphic as a GDIMetaFile.
VCL_DLLPUBLIC bool ImportPDF(SvStream& rStream, Bitmap& rBitmap,
                             css::uno::Sequence<sal_Int8>& rPdfData,
                             sal_uInt64 nPos = STREAM_SEEK_TO_BEGIN,
                             sal_uInt64 nSize = STREAM_SEEK_TO_END);
VCL_DLLPUBLIC bool ImportPDF(SvStream& rStream, Graphic& rGraphic);

}

#endif // INCLUDED_VCL_SOURCE_FILTER_IPDF_PDFREAD_HXX

/* vim:set shiftwidth=4 softtabstop=4 expandtab: */
