/*******************************************************************
* Copyright (c) 2009 Thomas Fannes (thomasfannes@gmail.com)
*
* Permission is hereby granted, free of charge, to any person
* obtaining a copy of this software and associated documentation
* files (the "Software"), to deal in the Software without
* restriction, including without limitation the rights to use,
* copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the
* Software is furnished to do so, subject to the following
* conditions:
*
* The above copyright notice and this permission notice shall be
* included in all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
* OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
* NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
* HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
* WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
* FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
* OTHER DEALINGS IN THE SOFTWARE.
*******************************************************************/

#ifndef DNDSEPARATORCONTROLLER_HPP
#define DNDSEPARATORCONTROLLER_HPP

#include "dndcontroller.hpp"
#include "util/macro.hpp"

namespace ruleSystem
{
	namespace graphicsView
	{
		class FunctionGraphicsItem;

		class DnDSeparatorController : public DnDController
		{
		public:
			DnDSeparatorController(FunctionGraphicsItem * functionItem, int pos);

			virtual bool canStartDrag() const;
			virtual bool acceptsDrag(const QMimeData * data);
			virtual Qt::DropAction onDrop(const QMimeData * data);
			virtual void itemDropped(Qt::DropAction action);

			PtrVarGetSet(FunctionGraphicsItem, functionItem, FunctionItem);
			SimpleVarGetSet(int, pos, Pos);
		};
	}
}

#endif // FUNCTIONSEPARATORDNDCONTROLLER_HPP
