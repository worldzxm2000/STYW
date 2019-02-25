#include "Dictionary.h"

Dictionary::Dictionary()
{
	//观察要素
	//水位
	map.insert("ys01", "WaterLevel");
	//传感器状态
	map.insert("st20", "AutoCheckSts1");
}

QString Dictionary::Find(QString key)
{
	QMap<QString, QString>::const_iterator mi = map.find(key);
	if (mi != map.end())
		return map[key];
	return NULL;
}
