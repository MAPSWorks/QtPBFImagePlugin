#include  <QPainter>
#include "textitem.h"


#define FLAGS (Qt::AlignCenter | Qt::TextWordWrap | Qt::TextDontClip)

TextItem::TextItem(const QString &text, const QPointF &pos, const QFont &font,
  int maxTextWidth, QGraphicsItem *parent) : QGraphicsItem(parent), _text(text),
  _font(font)
{
	QFontMetrics fm(font);
	int limit = font.pixelSize() * maxTextWidth;

	QRect br = fm.boundingRect(QRect(0, 0, limit, 0), FLAGS, text);
	Q_ASSERT(br.isValid());
	setPos((pos - QPointF(br.width() / 2.0, br.height() / 2.0)).toPoint());
	_boundingRect = QRectF(0, 0, br.width(), br.height());
}

void TextItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
  QWidget *widget)
{
	Q_UNUSED(option);
	Q_UNUSED(widget);

	painter->setFont(_font);
	painter->setPen(_pen);
	painter->drawText(_boundingRect, FLAGS, _text);
}