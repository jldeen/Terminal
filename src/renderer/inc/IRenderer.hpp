/*++
Copyright (c) Microsoft Corporation

Module Name:
- IRenderer.hpp

Abstract:
- This serves as the entry point for console rendering activites.

Author(s):
- Michael Niksa (MiNiksa) 17-Nov-2015
--*/

#pragma once

#include "FontInfoDesired.hpp"
#include "IRenderEngine.hpp"

namespace Microsoft::Console::Render
{
    class IRenderer
    {
    public:
        virtual ~IRenderer() {};

        [[nodiscard]]
        virtual HRESULT PaintFrame() = 0;

        virtual void TriggerSystemRedraw(const RECT* const prcDirtyClient) = 0;

        virtual void TriggerRedraw(const SMALL_RECT* const psrRegion) = 0;
        virtual void TriggerRedraw(const COORD* const pcoord) = 0;
        virtual void TriggerRedrawCursor(const COORD* const pcoord) = 0;

        virtual void TriggerRedrawAll() = 0;
        virtual void TriggerTeardown() = 0;

        virtual void TriggerSelection() = 0;
        virtual void TriggerScroll() = 0;
        virtual void TriggerScroll(const COORD* const pcoordDelta) = 0;
        virtual void TriggerCircling() = 0;
        virtual void TriggerTitleChange() = 0;
        virtual void TriggerFontChange(const int iDpi,
                                       const FontInfoDesired * const pFontInfoDesired,
                                       _Out_ FontInfo* const pFontInfo) = 0;

        [[nodiscard]]
        virtual HRESULT GetProposedFont(const int iDpi,
                                        const FontInfoDesired * const pFontInfoDesired,
                                        _Out_ FontInfo* const pFontInfo) = 0;

        virtual COORD GetFontSize() = 0;
        virtual bool IsCharFullWidthByFont(const WCHAR wch) = 0;

        virtual void EnablePainting() = 0;
        virtual void WaitForPaintCompletionAndDisable(const DWORD dwTimeoutMs) = 0;

        virtual void AddRenderEngine(_In_ IRenderEngine* const pEngine) = 0;
    };
}
