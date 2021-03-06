/* -*- Mode: C++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */
/*
 * This file is part of the LibreOffice project.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 * This file incorporates work covered by the following license notice:
 *
 *   Licensed to the Apache Software Foundation (ASF) under one or more
 *   contributor license agreements. See the NOTICE file distributed
 *   with this work for additional information regarding copyright
 *   ownership. The ASF licenses this file to you under the Apache
 *   License, Version 2.0 (the "License"); you may not use this file
 *   except in compliance with the License. You may obtain a copy of
 *   the License at http://www.apache.org/licenses/LICENSE-2.0 .
 */

#include <dialmgr.hxx>
#include <svx/svxdlg.hxx>
#include <vcl/svapp.hxx>
#include <strings.hrc>
#include <insrc.hxx>

bool SvxInsRowColDlg::isInsertBefore() const
{
    return !m_xAfterBtn->get_active();
}

sal_uInt16 SvxInsRowColDlg::getInsertCount() const
{
    return m_xCountEdit->get_value();
}

SvxInsRowColDlg::SvxInsRowColDlg(weld::Window* pParent, bool bCol, const OString& rHelpId)
    : m_xBuilder(Application::CreateBuilder(pParent, "cui/ui/insertrowcolumn.ui"))
    , m_xDialog(m_xBuilder->weld_dialog("InsertRowColumnDialog"))
    , m_xCountEdit(m_xBuilder->weld_spin_button("insert_number"))
    , m_xBeforeBtn(m_xBuilder->weld_radio_button("insert_before"))
    , m_xAfterBtn(m_xBuilder->weld_radio_button("insert_after"))
    , aRow(CuiResId(RID_SVXSTR_ROW))
    , aCol(CuiResId(RID_SVXSTR_COL))
    , bColumn(bCol)
{
    m_xDialog->set_title(bColumn ? aCol : aRow);
    m_xDialog->set_help_id(rHelpId);
}

short SvxInsRowColDlg::Execute()
{
    return m_xDialog->run();
}

/* vim:set shiftwidth=4 softtabstop=4 expandtab: */
