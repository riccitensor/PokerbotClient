/*******************************************************************
* Copyright (c) 2010 Thomas Fannes (thomasfannes@gmail.com)
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

#include "reader.hpp"
#include "qjson/src/json_parser.hh"

#include <QFile>

Reader::Reader(QObject *parent)
	:QObject(parent)
{
	read = false;
	errored = false;
}

void Reader::readJSON(){
	read = true;
	QFile file("config.json");
	if (!file.open (QIODevice::ReadOnly)){
		emit noConfigFile();
		return;
	}

	json = file.readAll();
	file.close();
}

QUrl Reader::getURL(){
	return QUrl(value("URL"));
}

QUrl Reader::getHelloURL(){
	return QUrl(value("URL") + "/" + value("hello"));
}

QUrl Reader::getJoinTableURL(){
	return QUrl(value("URL")+ "/" + value("joinTable"));
}

QUrl Reader::getWatchTableURL(){
	return QUrl(value("URL") + "/" + value("watchTable"));
}

QUrl Reader::getGoodbyeURL(){
	return QUrl(value("URL") + "/" + value("goodbye"));
}

QString Reader::value(QString key){
	if(!read){
		readJSON();
	}

	QJson::Parser parser;
	bool ok;
	QVariantMap result = parser.parse(json, &ok).toMap();
	if(!ok){
		if(!errored){
			errored = true;
			emit wrongConfigFile();
		}
	}

	QVariant postfix = result.value(key);

	return postfix.toString();
}
