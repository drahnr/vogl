#ifndef VOGLEDITOR_QTEXTUREEXPLORER_H
#define VOGLEDITOR_QTEXTUREEXPLORER_H

#include <QWidget>

#include "vogl_core.h"
#include "vogleditor_qtextureviewer.h"

class vogl_gl_object_state;
typedef vogl::vector<vogl_gl_object_state *> vogl_gl_object_state_ptr_vec;

class vogl_texture_state;

namespace Ui {
class vogleditor_QTextureExplorer;
}

class vogleditor_QTextureExplorer : public QWidget
{
    Q_OBJECT

public:
    explicit vogleditor_QTextureExplorer(QWidget *parent = 0);
    ~vogleditor_QTextureExplorer();

    void set_texture_objects(vogl_gl_object_state_ptr_vec objects);
    void add_texture_object(vogl_texture_state& textureState, vogl::dynamic_string bufferType);

    bool set_active_texture(unsigned long long textureHandle);

    void clear();

    unsigned int get_preferred_height() const;

    void set_zoom_factor(double zoomFactor);

private:
    Ui::vogleditor_QTextureExplorer *ui;
    vogl_gl_object_state_ptr_vec m_objects;
    QTextureViewer m_textureViewer;

private slots:
    void selectedTextureIndexChanged(int index);
    void channelSelectionChanged(int index);
    void alphaBlendButtonClicked();
    void on_zoomSpinBox_valueChanged(double zoomFactor);
    void on_pushButton_toggled(bool checked);

    void on_sampleSpinBox_valueChanged(int sample);

signals:
    void zoomFactorChanged(double zoomFactor);
};

#endif // VOGLEDITOR_QTEXTUREEXPLORER_H
