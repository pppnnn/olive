#ifndef NODEUI_H
#define NODEUI_H

#include <QWidget>
#include <QGraphicsItem>

class EffectUI;
class EffectRow;
class NodeEdge;
class Node;

class NodeUI : public QGraphicsRectItem {
public:
  NodeUI();

  void AddToScene(QGraphicsScene* scene);
  //void Resize(const QSize& s);
  void SetNode(Node* n);
  Node* GetNode();

  QVector<QRectF> GetNodeSocketRects();

protected:
  virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;

  virtual void mousePressEvent(QGraphicsSceneMouseEvent * event) override;
  virtual void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
  virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

private:
  EffectRow *GetRowFromIndex(int i);
  NodeUI* FindUIFromNode(Node* n);
  int GetRowY(int index);

  Node* node_;

  QGraphicsPathItem* drag_line_;
  QPointF drag_line_start_;
  EffectRow* drag_source_;
  EffectRow* drag_destination_;
  QPainterPath drag_path_;

  int clicked_socket_;

};



#endif // NODEUI_H
