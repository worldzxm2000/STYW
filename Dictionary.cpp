#include "Dictionary.h"

Dictionary::Dictionary()
{
	//�۲�Ҫ��
	//ˮλ
	map.insert("ys01", "WaterLevel");
	//������״̬
	map.insert("st20", "AutoCheckSts1");
}

QString Dictionary::Find(QString key)
{
	QMap<QString, QString>::const_iterator mi = map.find(key);
	if (mi != map.end())
		return map[key];
	return NULL;
}
