/*
	QMPlay2 is a video and audio player.
	Copyright (C) 2010-2017  Błażej Szczygieł

	This program is free software: you can redistribute it and/or modify
	it under the terms of the GNU Lesser General Public License as published
	by the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU Lesser General Public License for more details.

	You should have received a copy of the GNU Lesser General Public License
	along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <Module.hpp>

class PortAudio : public Module
{
public:
	PortAudio();
	~PortAudio();
private:
	QList<Info> getModulesInfo(const bool) const override final;
	void *createInstance(const QString &) override final;

	SettingsWidget *getSettingsWidget() override final;

	bool initialized;
};

/**/

#include <QCoreApplication>

class QDoubleSpinBox;
class QCheckBox;
class QComboBox;

class ModuleSettingsWidget : public Module::SettingsWidget
{
	Q_DECLARE_TR_FUNCTIONS(ModuleSettingsWidget)
public:
	ModuleSettingsWidget(Module &);
private:
	void saveSettings() override final;

	QCheckBox *enabledB;
	QComboBox *devicesB;
	QDoubleSpinBox *delayB;
};
