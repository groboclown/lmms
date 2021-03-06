/*
 * bassbooster_control_dialog.cpp - control-dialog for bassbooster-effect
 *
 * Copyright (c) 2006-2008 Tobias Doerffel <tobydox/at/users.sourceforge.net>
 * 
 * This file is part of Linux MultiMedia Studio - http://lmms.sourceforge.net
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public
 * License along with this program (see COPYING); if not, write to the
 * Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301 USA.
 *
 */


#include <QtGui/QLayout>

#include "bassbooster_control_dialog.h"
#include "bassbooster_controls.h"
#include "embed.h"



bassBoosterControlDialog::bassBoosterControlDialog(
					bassBoosterControls * _controls ) :
	EffectControlDialog( _controls )
{
	setAutoFillBackground( true );
	QPalette pal;
	pal.setBrush( backgroundRole(),
				PLUGIN_NAME::getIconPixmap( "artwork" ) );
	setPalette( pal );
	setFixedSize( 120, 104 );

	QVBoxLayout * tl = new QVBoxLayout( this );
	tl->addSpacing( 30 );

	QHBoxLayout * l = new QHBoxLayout;

	knob * freqKnob = new knob( knobBright_26, this);
	freqKnob->setModel( &_controls->m_freqModel );
	freqKnob->setLabel( tr( "FREQ" ) );
	freqKnob->setHintText( tr( "Frequency:" ) + " ", "Hz" );

	knob * gainKnob = new knob( knobBright_26, this );
	gainKnob->setModel( &_controls->m_gainModel );
	gainKnob->setLabel( tr( "GAIN" ) );
	gainKnob->setHintText( tr( "Gain:" ) + " ", "" );

	knob * ratioKnob = new knob( knobBright_26, this );
	ratioKnob->setModel( &_controls->m_ratioModel );
	ratioKnob->setLabel( tr( "RATIO" ) );
	ratioKnob->setHintText( tr( "Ratio:" ) + " ", "" );

	l->addWidget( freqKnob );
	l->addWidget( gainKnob );
	l->addWidget( ratioKnob );

	tl->addLayout( l );
	setLayout( tl );
}


